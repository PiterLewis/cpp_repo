/*
Autor : Santiago García Domínguez
Curso : 2ºINSO A 
Fecha : 07/03/2025
Descripción: Fibonnaci
*/
#include<iostream>
#define NUM 6
using namespace std;
int funcion(int x);
int fibonacci(int n);
int main(){

    int res = 0;
    cout << "Debug";

    res = fibonacci(NUM);
    
    cout << "Numero: " << NUM << "\t";
    cout << "total : " << res;
    
}

int fibonacci(int n){
    // n es el numero de recursiones
    // si fibonacci se basa en la suma de 0 a inf
    // hacemos un contador y hasta que no iguale a la entrada
    // o n, no paramos de sumar
    
    // casos base : n = 0 y n = 1.
    // dan valor a fib (2) = fib(1) + fib(0)
    
    if(n == 0){
        return 0;
    }else if(n == 1){
        return 1;
    }else{
        return fibonacci(n-1) + fibonacci(n-2);
    }

}
