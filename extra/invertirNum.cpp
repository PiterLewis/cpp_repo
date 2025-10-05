#include <iostream>
#include <cmath>  // Para log10() y pow()
using namespace std;

int invertirNumHelper(int x, int potencia);
int invertirNum(int x);

int main() {
    int numerin = 12345;
    int res = invertirNum(numerin);

    cout << "Número invertido: " << res << endl;
    return 0;
}

// Función principal que calcula la cantidad de dígitos y llama a la recursiva auxiliar
int invertirNum(int x) {
    int numDigitos = log10(x) + 1;  // Calculamos la cantidad de dígitos
    return invertirNumHelper(x, pow(10, numDigitos - 1));
}

// Función recursiva auxiliar para invertir el número
int invertirNumHelper(int x, int potencia) {
    // Caso base: si el número tiene un solo dígito, lo devolvemos
    if (x < 10) {
        return x * potencia;
    }
    // Extraemos el último dígito y lo colocamos en la posición correcta
    return (x % 10) * potencia + invertirNumHelper(x / 10, potencia / 10);
}
