#include <iostream>
#include <string>
using namespace std;

// Función auxiliar para intercambiar caracteres en la cadena
void swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

// Función recursiva para generar permutaciones con debug
void permutar(string &str, int inicio, int fin) {
    cout << "Llamada: permutar(\"" << str << "\", " << inicio << ", " << fin << ")" << endl;
    
    // Caso base: si hemos fijado todos los caracteres, imprimimos la permutación
    if (inicio == fin) {
        cout << "Permutación encontrada: " << str << endl;
        return;
    }

    // Recorremos cada posición para intercambiar y generar nuevas permutaciones
    for (int i = inicio; i <= fin; i++) {
        cout << "Intercambiando " << str[inicio] << " con " << str[i] << " en la posición " << inicio << endl;
        swap(str[inicio], str[i]);  // Intercambiamos caracteres
        cout << "Cadena actual: " << str << endl;
        
        permutar(str, inicio + 1, fin);  // Llamada recursiva

        swap(str[inicio], str[i]);  // Volvemos a la configuración original (Backtracking)
        cout << "Volviendo atrás (backtracking): " << str << endl;
    }
}

int main() {
    string cadena;
    cout << "Ingresa una palabra: ";
    cin >> cadena;

    cout << "\nGenerando permutaciones:\n";
    permutar(cadena, 0, cadena.length() - 1);

    return 0;
}
