/*
Autor : Santiago García Domínguez
Curso : 2ºINSO A 
Fecha : 07/03/2025
Descripción: programa que suma los primeros n 
numeros naturales.
*/
#include<iostream>
#define NUM 4
using namespace std;

int numerosNaturales(int n);
int main(){

    int res = numerosNaturales(NUM);
    cout << "Numero: " << NUM << "\t";
    cout << "total : " << res;
    
}

int numerosNaturales(int n){
    // caso base : n sea 1
    if(n == 1){
        return 1;
    }else{
        // se realizan N llamadas al stack, hasta
        // que N es igual a 1. Lo que devuelve 1 y 
        // damos por terminada la recursión.
        return n + numerosNaturales(n-1);
    }
}
