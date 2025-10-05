#include <iostream>
using namespace std;

const int MAX = 10;  // tamaño máximo para arrays

void backtrackingCombinaciones(
    int permitidos[],     // dígitos permitidos
    int combinacion[],    // combinación actual
    int cantidad,         // cantidad de dígitos permitidos
    int n,                // suma objetivo
    int k,                // número de elementos que queremos usar
    int pos,              // desde qué posición seguir probando
    int suma_actual,      // suma parcial
    int usados            // cuántos números llevamos puestos
) {
    // Caso base: si ya usamos k números
    if (usados == k) {
        if (suma_actual == n) {
            // Imprimir la combinación válida
            for (int i = 0; i < k; i++) {
                cout << combinacion[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    // Probar cada valor a partir de pos (para evitar repeticiones)
    for (int i = pos; i < cantidad; i++) {
        int valor = permitidos[i];
        if (suma_actual + valor <= n) {
            combinacion[usados] = valor;  // colocar valor en la combinación
            backtrackingCombinaciones(permitidos, combinacion, cantidad, n, k, i, suma_actual + valor, usados + 1);
            // No es necesario "deshacer" porque sobreescribimos en la siguiente llamada
        }
    }
}

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

    re