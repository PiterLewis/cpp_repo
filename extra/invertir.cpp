#include <iostream>
#include <cstring>  // Para strlen y strcpy
using namespace std;

char* invertir(const char* cadena) {
    int longitud = strlen(cadena);  // Obtener la longitud de la cadena
    
    // Caso base: si la cadena está vacía o tiene un solo carácter, se devuelve igual
    if (longitud <= 1) {
        char* resultado = new char[longitud + 1]; // Reservamos memoria
        strcpy(resultado, cadena); // Copiamos la cadena original
        return resultado;
    }

    // Reservamos memoria para la nueva cadena invertida
    char* resultado = new char[longitud + 1]; // +1 para el '\0'

    // Llamada recursiva para invertir el resto de la cadena sin el primer carácter
    char* invertido = invertir(cadena + 1); 

    // Copiar el resultado recursivo y añadir el primer carácter al final
    strcpy(resultado, invertido); // Copiamos lo invertido en resultado
    resultado[longitud - 1] = cadena[0]; // Colocamos el primer carácter al final
    resultado[longitud] = '\0'; // Asegurar el final de la cadena

    // Liberamos la memoria del resultado intermedio
    delete[] invertido;

    return resultado;
}

int main() {
    const char* cadena = "hola";
    char* cadenaInvertida = invertir(cadena); // Llamada recursiva

    cout << "Cadena original: " << cadena << endl;
    cout << "Cadena invertida: " << cadenaInvertida << endl;

    delete[] cadenaInvertida; // Liberamos la memoria dinámica

    return 0;
}
