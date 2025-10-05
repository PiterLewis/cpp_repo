#include <iostream>
#include <cstring>
#include "cabeceras.h"
// hacer un programa que introduzcas nombres
// y los guarde en una matriz de nombres
// le metemos un .h para cabeceras

int main(){
    
    char* nombre = NULL;
    char** matrix = NULL;

    //fallo en crearMatriz
    crearMatriz(matrix);
    pedirNombres();

    for(int i = 0; i < MAX_NOMBRES; i++){
        guardarNombres(nombre);
        // creo que peta aqui
        strcpy(matrix[i], nombre);
        // liberar mem de nombre
        delete[] nombre;
        nombre = NULL;
    }
    printMatrix(matrix);
    // liberar memoria de la matriz
    liberarMatrix(matrix, MAX_NOMBRES);
}

void pedirNombres(){
    std::cout<< "¿Que nombres?" << std::endl;
}
void  guardarNombres(char* &nombre){
    // Reservamos memoria para nombre y devolvemos array
    // para poder sustituir el nombre en la matriz
    nombre = new char[MAX_TAM];
    std::cin >> nombre;
    std::cout << "Nombre guardado" << std::endl;
}

void crearMatriz(char** &matrix){
   
   // fallor en la creación de la matriz
    matrix = new char*[MAX_NOMBRES];
    for(int i = 0; i <= MAX_NOMBRES; i++){
        matrix[i] = new char[MAX_TAM];
    }
   // prueba
   std:: cout << "matriz instanciada" << std::endl;
}

void printMatrix(char** matrix){
    for(int i = 0; i <= MAX_NOMBRES; i++){
        std::cout << matrix[i] << std::endl;
    }
}

void liberarMatrix(char** matrix, int filas) {
    for (int i = 0; i < filas; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}