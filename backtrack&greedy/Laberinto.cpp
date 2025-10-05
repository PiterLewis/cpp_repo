/*
@author Santiago Garcia Dominguez
Fecha: 09/03/2025
*/
#include <iostream>
#define MAX_TAM 10
using namespace std;

bool casillaSegura(char laberinto[10][10], int x, int y); // esta funcion es para comprobar la casilla '.'
bool buscarTesoro(char laberinto[10][10], int x, int y);

int main() {
    char laberinto[MAX_TAM][MAX_TAM];
    int tesoroX = -1, tesoroY = -1;  

    // Leer el laberinto
    for(int i = 0; i < MAX_TAM; i++){
        for(int j = 0; j < MAX_TAM; j++){
            cin >> laberinto[i][j]; 
        }
    }

    //si el resultado de buscartesoro es true, imprime el mapa y señala encontrado.
    //si es false -> cout inalcanzable. 
    if (buscarTesoro(laberinto, 0, 0)) {
        // imprimir el mapa con el camino marcado
        for(int i = 0; i < MAX_TAM; i++){
            for(int j = 0; j < MAX_TAM; j++){
                cout << laberinto[i][j];
            }
            cout << endl;
        }

        
        for(int i = 0; i < MAX_TAM; i++){
            for(int j = 0; j < MAX_TAM; j++){
                if(laberinto[i][j] == 'T'){
                    tesoroX = i;
                    tesoroY = j;
                }
            }
        }

        cout << "ENCONTRADO " << tesoroX << " " << tesoroY << endl;
    } else {
        cout << "INALCANZABLE" << endl;
    }

    return 0;
}

bool buscarTesoro(char laberinto[10][10], int x, int y) {
    if (laberinto[x][y] == 'T') { // si encuentra el tesoro, acaba con true la funcion
        return true;
    }

    if (casillaSegura(laberinto, x, y)) {
        laberinto[x][y] = 'X'; // marcar como visitado 'X'

        if (buscarTesoro(laberinto, x-1, y)) return true; // arriba
        if (buscarTesoro(laberinto, x, y+1)) return true; // derecha
        if (buscarTesoro(laberinto, x+1, y)) return true; // abajo
        if (buscarTesoro(laberinto, x, y-1)) return true; // izquierda

        laberinto[x][y] = '.'; // vuelve a marcar como punto si no hay mov disponibles.
    }
    return false;
}

bool casillaSegura(char laberinto[10][10], int x, int y) {
    return !(x < 0 || x >= 10 || y < 0 || y >= 10 || laberinto[x][y] == '*' || laberinto[x][y] == 'X');
    //devuelve true si la condicion NO se da. en caso contrario devuelve false.
    //basicamente comprueba los limites del mapa o si la casilla es X o * (pared o ya visitada)
}
