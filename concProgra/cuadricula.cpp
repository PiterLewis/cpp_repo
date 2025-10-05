#include <iostream>
using namespace std;

#define N 4  // tamaño del sudoku

bool esValido(int sudoku[N][N], int fila, int col, int num);
bool resolverSudoku(int sudoku[N][N], int fila, int col);

int main() {
    int sudoku[N][N] = {
        {1, 0, 0, 4},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {2, 0, 0, 3}
    };

    cout << "Antes:\n";
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }

    if(resolverSudoku(sudoku, 0, 0)) {
        cout << "\nDespués:\n";
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cout << sudoku[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "\nNo tiene solución.\n";
    }

    return 0;
}

bool resolverSudoku(int sudoku[N][N], int fila, int col) {
    if (fila == N) return true;  // caso base: hemos terminado

    // Siguiente posición
    int nextFila = (col == N - 1) ? fila + 1 : fila;
    int nextCol = (col + 1) % N;

    if (sudoku[fila][col] != 0) {
        return resolverSudoku(sudoku, nextFila, nextCol);  // ya está rellena
    }

    for (int num = 1; num <= N; num++) {
        if (esValido(sudoku, fila, col, num)) {
            sudoku[fila][col] = num;

            if (resolverSudoku(sudoku, nextFila, nextCol))
                return true;

            sudoku[fila][col] = 0;  // backtrack
        }
    }

    return false;
}

bool esValido(int sudoku[N][N], int fila, int col, int num) {
    for (int i = 0; i < N; i++) {
        if (sudoku[fila][i] == num || sudoku[i][col] == num)
            return false;
    }
    return true;
}
