#include <iostream>
using namespace std;

void generarBits(int n, string secuencia) {
    // Caso base: si la secuencia tiene n caracteres, la imprimimos
    if (secuencia.length() == n) {
        cout << secuencia << endl;
        return;
    }

    // Intentamos agregar un '0' y exploramos
    generarBits(n, secuencia + "0");

    // Intentamos agregar un '1' y exploramos
    generarBits(n, secuencia + "1");
}

int main() {
    int n;
    cout << "Introduce la cantidad de bits: ";
    cin >> n;

    generarBits(n, "");

    return 0;
}
