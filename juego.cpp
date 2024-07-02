#include "iostream"
#include "string"
#include "ctime"
#include "cstdlib"
#include "unistd.h"
using namespace std;

//NUMERO YA MENCIONADO POR EL BOT YA NO VOLVERLO A DECIR
// Prototipo de función
bool yaColocado(int, int mat[3][3]);
bool tableroCompleto(int mat[3][3]);
void marcarNumero(int, int mat[3][3]);

int main(void)
{
    srand(time(0));
    int numAl, opc, opcion;
    string arrjug[2];
    bool juegoTerminado = false;
    int mat[2][3][3] = {0}; // Matrices para los dos jugadores

do {
cout << "Seleccione la opcion que desee: " << endl;
cout << "1. NUEVA PARTIDA" << endl;     
cout << "2. REGISTRO DE PARTIDAS" << endl; 
cout << "3. REGISTRO DE GANADORES" << endl; 
cout << "4. INTEGRANTES DE MAX" << endl; 
cout << "5. SALIR DEL JUEGO" << endl;
cin >> opc;

        switch (opc) {

          case 1: 
                for (int i = 0; i < 2; i++) {
                cout << "Ingrese el nombre del jugador " << (i + 1) << " : ";
                cin >> arrjug[i];
            }

            cout << endl << "Los nombres de los jugadores son: " << endl;
            for (int i = 0; i < 2; i++) {
                cout << "Jugador " << (i + 1) << " : " << arrjug[i] << endl;
            }

            cout << endl << endl << "HAZ INICIADO UNA NUEVA PARTIDA!" << endl << endl;
            cout << endl << "TABLEROS DE JUGADORES" << endl << endl;

            // Generar y mostrar los tableros para cada jugador
            for (int k = 0; k < 2; k++) {
                cout << "Tablero del jugador " << arrjug[k] << " : " << endl << endl;

                // Generar números aleatorios únicos para cada tablero
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        do {
                            numAl = 1 + rand() % 20;
                        } while (yaColocado(numAl, mat[k]));
                        mat[k][i][j] = numAl;
                    }
                }

                // Mostrar el tablero del jugador
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        cout << mat[k][i][j] << "  ";
                    }
                    cout << endl << endl;
                }

            }

            // Pausa antes de que el bot comience a generar números
            cout << "Presione Enter para que el bot genere el primer numero..." << endl;
            cin.ignore(); // Ignorar el carácter de nueva línea residual del último cin
            cin.get();

            // Bucle para generar números aleatorios y marcar en los tableros
            
            while (!juegoTerminado) { 
                
                numAl = 1 + rand() % 20;
                cout << endl << endl << "Numero generado por el bot: " << numAl << endl << endl;

                for (int k = 0; k < 2; k++) {
                    marcarNumero(numAl, mat[k]);
                }

                // Mostrar los tableros actualizados
                for (int k = 0; k < 2; k++) {
                    cout << "Tablero del jugador " << arrjug[k] << " actualizado : " << endl << endl;
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            cout << mat[k][i][j] << "  ";
                        }
                        cout << endl << endl;
                    }
                }

                        // Pausa entre generaciones de números
                sleep(1);

                for (int k = 0; k < 2; k++) {

                    if (tableroCompleto(mat[k])) {
                        cout << endl << "EL JUGADOR " << arrjug[k] << " HA GANADO LA PARTIDA!" << endl;
                        juegoTerminado = true;

                        cout << endl << endl << "LA PARTIDA HA TERMINADO..." << endl << endl;
                        break;
                    }
                }
            
                // do while para que las opciones no se muestren cuando este completo de ceros 
                
                cout << "1. Mostrar la ayuda" << endl;
                cout << "2. Continuar con la partida" << endl;
                cin >> opcion; 

                if(opcion ==1){
                    cout << "AYUDA" << endl;
                    cout << "reglas" << endl; 
                    // Opción para continuar
                    cout << "Presione Enter para continuar con la partida..." << endl;
                    cin.ignore();
                    cin.get();
                    
                }
                else if(opcion ==2){
                    cout <<" " << endl; 
                }
                
                
                sleep(1);

            }

                    break;

                    case 2: 

                    cout << endl << " REGISTRO DE PARTIDAS " << endl << endl;
            
                    break; 

                    case 3: 
                    cout << endl << "REGISTRO DE GANADORES" << endl << endl;
                
                    break;

                    case 4:
                
                    cout << endl << "INTEGRANTES DE MAX" << endl << endl;
                    cout << endl << "Ana Belen Ramirez Flores 00183224" << endl;
                    cout << endl << "Xochill Guissell Miguel Miranda 00114924" << endl;
                    cout << endl << "Maria Fernanda Ramirez Portillo 00127724" << endl;
                    cout << endl << endl;
                break;

                    case 5: 
                        
                        cout << endl << endl; 
                        
                        cout << endl << "Has salido del juego" << endl;

                        cout << endl << endl;   

                break;

                default:
                cout << "Opcion no valida. Por favor, seleccione 1 o 5." << endl;
                }

    } while (opc != 5);
 return 0;

}

void marcarNumero(int num, int mat[3][3])
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (mat[i][j] == num) {
                mat[i][j] = 0;
            }
        }
    }
    
}