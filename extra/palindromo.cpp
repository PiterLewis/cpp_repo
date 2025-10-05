#include <iostream>
#include <cstring>

#define MAX_TAM 10
using namespace std;
bool esPalindromo(char *cadena, int longitud, int inicio);

int main(){

    char cadena[MAX_TAM];
    cin >> cadena;
    char *ptr = cadena;
    int tamanio = strlen(cadena) - 1;
    int inicio = 0;
    if(esPalindromo(ptr, tamanio, inicio)){
        cout << "Es palindromo";
    }else
        cout << "no es";

}

bool esPalindromo(char *cadena, int longitud, int inicio){

    if(inicio >= longitud || inicio == longitud){
        return true;
    }if(cadena[inicio] != cadena[longitud]){
        return false;
    }else{
        return esPalindromo(cadena, longitud -1, inicio +1);
    }
}