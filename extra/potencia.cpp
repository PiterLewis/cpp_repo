/*
Autor : Santiago García Domínguez
Curso : 2ºINSO A 
Fecha : 07/03/2025
Descripción: Potencia Recursiva
*/
#include<iostream>
using namespace std;

int potencia(int n, int pow);
int main(){

   int num = 0;
   int pow = 0;

   cin >> num ;
   cin >> pow ;

   int res = potencia(num, pow); 
   cout << res;
}

int potencia(int n, int pow){

    
    // caso base cu
    if(pow == 1){
        return n;
    }else{
        return n * potencia(n, pow-1);
    }
}
