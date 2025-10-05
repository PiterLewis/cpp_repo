#include <iostream>
using namespace std;

#define MAX 10

void backtrackingCombinaciones(
    int permitidos[], int combinacion[], int cantidad,
    int n, int k, int pos, int suma_actual, int usados
);

int main() {
    int n, k, cantidad;
    int permitidos[MAX];

    while (true) {
        cin >> n >> k >> cantidad;
        if (n == 0 && k == 0 && cantidad == 0) break;

        for (int i = 0; i < cantidad; i++) {
            cin >> permitidos[i];
        }

        int combinacion[MAX];  // combinación actual vacía
        cout << "Soluciones para N = " << n << ", K = " << k << ": " << endl;
        backtrackingCombinaciones(permitidos, combinacion, cantidad, n, k, 0, 0, 0);
    }

    return 0;
}

void backtrackingCombinaciones(
    int permitidos[], int combinacion[], int cantidad,
    int n, int k, int pos, int suma_actual, int usados
) {
    // MOSTRAR lo que se está probando ahora mismo
    cout << "Probando: ";
    for (int i = 0; i < usados; i++) {
        cout << combinacion[i] << " ";
    }
    cout << "(suma = " << suma_actual << ")" << endl;

    // Caso base
    if (usados == k) {
        if (suma_actual == n) {
            cout << "Solucion encontrada: ";
            for (int i = 0; i < k; i++) {
                cout << combinacion[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    // Llamadas recursivas
    for (int i = pos; i < cantidad; i++) {
        int valor = permitidos[i];
        if (suma_actual + valor <= n) {
            combinacion[usados] = valor;
            backtrackingCombinaciones(
                permitidos, combinacion, cantidad, n, k,
                i, suma_actual + valor, usados + 1
            );
        }
    }
}

