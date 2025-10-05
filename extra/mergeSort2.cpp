#include <iostream>

void dividir(int cadena[], int longitud, int inicio);
int main(){

    int cadena[] = {8,3,2,9,7,1,5,4};
    int longitud = 8;
    dividir(cadena, longitud, 0);

}
void dividir(int cadena[], int longitud, int inicio){

    // caso base: elemento sea unitario, es decir long = inicio
    if(inicio >= longitud){ // -> Esto se hace por si hemos alcanzado
        return;             // la division del programa hasta la unidad
    }
    
    int mitad = inicio + (longitud - inicio) / 2; // designamos la mitad del array
    dividir(cadena, inicio, mitad); //comenzamos la división del array hasta la unidad
    dividir(cadena, mitad+1, longitud);//el return vuelve y divide la segunda mitad.

    

}