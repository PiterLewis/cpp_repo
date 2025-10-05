#include <iostream>
#define N 4  // Tamaño del laberinto
using namespace std;

// Función para verificar si una celda es válida para moverse
bool esValida(int laberinto[N][N], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && laberinto[x][y] == 1);
}

// Función recursiva para resolver el laberinto
bool resolverLaberinto(int laberinto[N][N], int x, int y, int solucion[N][N]) {
    // Caso base: Si llegamos a la salida
    if (x == N - 1 && y == N - 1) {
        solucion[x][y] = 1;
        return true;
    }

    // Si la celda actual es válida
    if (esValida(laberinto, x, y)) {
        solucion[x][y] = 1; // Marcar la celda como parte del camino

        // Intentar moverse en 4 direcciones: abajo, derecha, arriba, izquierda
        if (resolverLaberinto(laberinto, x + 1, y, solucion)) return true; // Abajo
        if (resolverLaberinto(laberinto, x, y + 1, solucion)) return true; // Derecha
        if (resolverLaberinto(laberinto, x - 1, y, solucion)) return true; // Arriba
        if (resolverLaberinto(laberinto, x, y - 1, solucion)) return true; // Izquierda

        // Si ninguna dirección funciona, deshacer el movimiento (backtrack)
        solucion[x][y] = 0;
    }

    return false;
}

// Función para imprimir la solución encontrada
void imprimirSolucion(int solucion[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << solucion[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int laberinto[N][N] = {
        {1, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1} // Salida en (3,3)
    };

    int solucion[N][N] = {0}; // Inicializamos la matriz de solución

    if (resolverLaberinto(laberinto, 0, 0, solucion)) {
        cout << "Solución encontrada:\n";
        imprimirSolucion(solucion);
    } else {
        cout << "No hay solución.\n";
    }

    return 0;
}
