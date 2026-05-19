#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main() {
    int x = 10;
    int numero_de_hijos = 3;

    cout << "--- [Padre inicial] PID: " << getpid() << " ---\n\n";
	int control;
    for (int i = 0; i < numero_de_hijos; i++) {
		cout << "continuar \n";
    	cin >> control;
        pid_t pid = fork();

        if (pid < 0) {
            cerr << "Error al crear el hijo " << i << "\n";
            return 1;
        }
        else if (pid == 0) {
            x = 20 + i;
            
            cout << "[Hijo " << i << "] PID: " << getpid() 
                 << " | padre: " << getppid() 
                 << " | x:" << x << "\n";
            
            exit(0); 
        }
    }

    cout << "\n[Padre] cerrando hijos\n";

    for (int i = 0; i < numero_de_hijos; i++) {
		cout << "cerrando nro: " << i << "\n";
        wait(NULL); 
    }

    cout << "continuar \n";
    cin >> control;

    cout << "[Padre] X: " << x << "\n";
    return 0;
}
