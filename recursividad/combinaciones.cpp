/*
Autor : Santiago García Domínguez
2ºINSO A
Fecha : 17/02/2025.
*/
#include <iostream>
using namespace std;


int factorial(int num1);
int main(){

    /*Llamada a la función*/
    int n, r, resultado;
    /* Formula
            n!
        ----------
        r! * (n-r)!

    */
    
    /* Control de errores */
    /* Con un do while */
    do{
        cin >> n;
        cin >> r;
        if (n < 0){
            return 0;
        }else if(r > n || r < 0){
            cout << "ERROR" << endl;
        }
        else{
            resultado = factorial(n) / (factorial(r) * factorial(n-r));
            cout << resultado << endl;
        }
        
    }while(true);
    
    /*while(n < r || r < 0){
        cin >> n;
        cin >> r;
        if (n < 0){
            return 0;
        }else if(r > n || r < 0){
            cout << "ERROR" << endl;
        }
        else{
            resultado = factorial(n) / (factorial(r) * factorial(n-r));
            cout << resultado << endl;
        }
    }
    */
    return 0;

}

int factorial(int num1){
    /* Recursividad en factorial */
    /*Caso base*/
    if(num1 == 0){
        return 1;
    }
    else{
        return num1*factorial(num1-1);
    }
}
// FACTORIAL -> 1 CUANDO N = 0 Y N = 1
// t(n) = 1 + t(n-1)
// o(n) = n
// si sumas on tres veces -> 3n = n más o menos.
