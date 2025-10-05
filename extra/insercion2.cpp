#include <iostream>
#include <cstring>
using namespace std;

void swap(int* elementoA, int* elementoB){
    int temp;
    temp = *elementoB; //guardamos en temp
    *elementoB = *elementoA; //B consigue el valor de A
    *elementoA = temp; // A consigue valor de temp 
}
void ordenacionInsercion(int lista[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        // Vamos "bajando" el elemento actual mientras sea menor que el anterior
        while (j > 0 && lista[j] < lista[j - 1]) {
            swap(&lista[j], &lista[j - 1]);
            j--;
        }
    }
}

int main(){
    int lista[] = {8,4,3,2,1,9,0};
    ordenacionInsercion(lista, 8);

    for(int i = 0; i<8; i++){
        cout << lista[i];
    }
}