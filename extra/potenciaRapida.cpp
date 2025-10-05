#include <iostream>
using namespace std;

/*
*   Algoritmo potencia rápida con divide y vencerás
*/


int potenciaRapida(int base, int exponente);
int main(){

    int base;
    cin >> base;
    int exponente;
    cin >> exponente;

    
    int res = potenciaRapida(base, exponente);
    cout << res;
    return 0;
}

int potenciaRapida(int base, int exponente){

    // caso base : exponente = 0
    if(exponente == 0){
        return 1;        
    }
    
    /*
    Tip para optimización.
        Este algoritmo es de tipo O(n)
        Si queremos que pase a ser O(log n)
        lo que es mucho más eficiente en términos
        de tiempo, necesitamos cambiar las llamadas recursivas
        por int mitad == potenciaRapida(base, exponente / 2);

        y luego el return mitad * mitad;
        En caso impar -> base * mitad * mitad;
    */

    int mitadPar = (exponente / 2);
    int mitadImpar = (exponente - 1) / 2;
    // si es par->formula
    if(exponente % 2 == 0){
        return potenciaRapida(base, mitadPar) * potenciaRapida(base, mitadPar);
    }else {
        return base * potenciaRapida(base, mitadImpar) * potenciaRapida(base, mitadImpar);
    } 


}

