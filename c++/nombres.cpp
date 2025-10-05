#include <iostream>
#include <cstring>

const int MAX_NOMBRES = 10; // Número máximo de nombres
const int MAX_TAM = 50;     // Tamaño máximo de cada nombre

char* pedirNombre();           // Función para pedir un nombre al usuario
char** crearMatriz(int filas); // Función para crear una matriz de cadenas
void printMatrix(char** matrix, int filas); // Imprimir la matriz
void liberarMatrix(char** matrix, int filas); // Liberar memoria de la matriz

int main() {
    char** matrix = crearMatriz(MAX_NOMBRES);

    std::cout << "Introduce hasta " << MAX_NOMBRES << " nombres:" << std::endl;

    for (int i = 0; i < MAX_NOMBRES; i++) {
        char* nombre = pedirNombre(); // Obtener un nombre del usuario
        strcpy(matrix[i], nombre);    // Copiar el nombre en la matriz
        delete[] nombre;              // Liberar la memoria del nombre temporal
    }

    std::cout << "\nNombres guardados:" << std::endl;
    printMatrix(matrix, MAX_NOMBRES);

    liberarMatrix(matrix, MAX_NOMBRES); // Liberar la memoria de la matriz
    return 0;
}

char* pedirNombre() {
    char* nombre = new char[MAX_TAM];
    std::cout << "Introduce un nombre: ";
    std::cin.getline(nombre, MAX_TAM); // Leer el nombre completo
    return nombre;
}

char** crearMatriz(int filas) {
    char** matrix = new char*[filas];
    for (int i = 0; i < filas; i++) {
        matrix[i] = new char[MAX_TAM]; // Reservar memoria para cada nombre
    }
    return matrix;
}

void printMatrix(char** matrix, int filas) {
    for (int i = 0; i < filas; i++) {
        std::cout << matrix[i] << std::endl;
    }
}

void liberarMatrix(char** matrix, int filas) {
    for (int i = 0; i < filas; i++) {
        delete[] matrix[i]; // Liberar memoria de cada nombre
    }
    delete[] matrix; // Liberar memoria de la matriz
}
