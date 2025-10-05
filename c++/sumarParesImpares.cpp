/*
Autor: Santiago Garcia Dominguez
INSO 2ºA
Fecha: 29 / 01 / 2025
*/

#include <iostream>

// Programa que lea un numero y que dependiendo
//  de si es par o impar calcule la suma de todos
//  los numeros pares o impares hasta dicho numero

// Cabecera de sumarPares
int sumarPares(int n);
int sumarImpares(int n);

int main(){

    // ejemplo valor 6 -> 12 = 2 + 4 + 6
    //  5 -> 9 = 1 + 3 + 5
    int n;
    std::cin >> n;

    if (n % 2 == 0){
        std::cout << sumarPares(n) << std::endl;
    }
    else{
        std::cout << sumarImpares(n) << std::endl;
    }
}

int sumarPares(int n){
    // acumulador de valores
    int suma = 0;

    // 0 es un valor vacío entonces lo ignoramos
    for (int i = 1; i <= n; i++){
        if (i % 2 == 0){
            suma += i;
        }
    }
    return suma;
}

int sumarImpares(int n){ 
    
    // igual que arriba
    int suma = 0;
    int i = 1;
    
    while(i <= n){
        if(i % 2 != 0){
            suma += i;
        }
        i++;
    }
    // intentamos hacerlo con un while también
    /*
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 != 0)
        {
            suma += i;
        }
    }
    */
    return suma;
}