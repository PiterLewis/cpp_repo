/*
*   Programa que ordena por inserción un array de números
*   @author: Santiago García Domínguez
*   @date : 29/04/2025
*   
*   El usuario introduce una secuencia de números de longitud desconocida
*   Solo los números impares deben ordenarse de menor a mayor
*   
*/


#include <iostream>
using namespace std;

void swap(int* elementoA, int* elementoB){
    int temp;
    temp = *elementoB; //guardamos en temp
    *elementoB = *elementoA; //B consigue el valor de A
    *elementoA = temp; // A consigue valor de temp 
}

int* guardarImpares(int lista[], int n) {
    // Contar cuántos números impares hay
    int cantidadImpares = 0;
    for (int i = 0; i < n; i++) {
        if (lista[i] % 2 != 0) {
            cantidadImpares++;
        }
    }

    // Crear un array dinamico con los impares
    int* impares = new int[cantidadImpares];
    int index = 0;

    // Guardar los impares en el nuevo array
    for (int i = 0; i < n; i++) {
        if (lista[i] % 2 != 0) {
            impares[index++] = lista[i];
        }
    }

    return impares;
}
void ordenacionInsercion(int lista[], int n) {
    int* arrayImpares = guardarImpares(lista, n);
    int cantidadImpares = 0;
    int aux = 0;
    for (int i = 0; i < n; i++) {
        if (lista[i] % 2 != 0) {
            cantidadImpares++;
        }
    }
    for (int i = 1; i < cantidadImpares; i++) {
        int j = i;
        while (j > 0 && arrayImpares[j] < arrayImpares[j - 1]) {
            swap(&arrayImpares[j], &arrayImpares[j - 1]);
            j--;
        }
    }
    
    for(int i = 0; i< n; i++){
        if(lista[i] %2 != 0){
            lista[i] = arrayImpares[aux];
            aux++;
        }
    }
}

int main(){
    int lista[] = {8,5,3,2,7,4,1};
    

    ordenacionInsercion(lista, 7);

    for(int i = 0; i<7; i++){
        cout << lista[i];
    }
}
