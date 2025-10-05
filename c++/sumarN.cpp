/*
Autor : Santiago Garcia Dominguez
INSO 2ºA
Fecha: 27 / 01 / 2025    
*/

#include <iostream>

// Programa que lea un numero y calcule la suma de
// todos los numeros del 1 hasta el numero indicado
int sumarNumeros(int n);

int main(){

    //declaramos la variable n y la leemos
    int n;
    std::cin >> n;

    //llamamos a la función sumarNumeros
    std::cout << sumarNumeros(n) << std::endl;
}

int sumarNumeros(int n){
    // suma para añadir el total de la suma
    int suma = 0;

    for(int i = 1; i <= n; i++){
        suma += i;
    }

    return suma;
}
    

