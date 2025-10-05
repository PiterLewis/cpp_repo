/*
Autor : Santiago García Domínguez
Curso : 2ºINSO A
Fecha : 21/02/2025.
*/
#include <iostream>
#include <cstring>
using namespace std;
#define TAM_BLOQUE 10
char* leerLineaDinamica();
bool esPalindromo(char *cadenaP, int inicio, int fin);
int main(){

    char *cadena;
    
    // leemos linea dinamicamente
    cadena = leerLineaDinamica();
    int longitud = strlen(cadena) - 1;
    bool resultado = esPalindromo(cadena, 0, longitud);
    // Como el booleano devuelve true o false
    // Usamos el operador ternario para poner 1 si es true
    // o 0 si es false
    cout << (resultado ? 1 : 0);
}

char* leerLineaDinamica(){
    char c;
    int i = 0;
    int tamanio = TAM_BLOQUE;
    char*cadena = new char[tamanio];

    while((c = getchar()) != '\n'){
        cadena[i] = c;
        i++;
        if(i == tamanio){
            tamanio += TAM_BLOQUE;
            char *nueva_cadena = new char[tamanio];
            
            /*
            Como no tenemos realloc
            hay que pasar el contenido de la cadena 
            a una cadena mayor
            */
            for(int j = 0 ; j< i; j++){
                nueva_cadena[j] = cadena[j];
            }
            delete[] cadena;
            cadena = nueva_cadena;
        }
    } 
    cadena[i] = '\0';

    return cadena;
}

bool esPalindromo(char *cadenaP, int inicio, int fin){
    /*Llamada recursiva*/
    /*Sizeof no funciona en este caso porque trabajamos
    punteros y no arrays estáticos
    int i = 0;
    int longitud = sizeof(cadenaP)/sizeof(cadenaP[i]);
    */
    
    if(inicio >= fin){
        return true;
    }
    if(cadenaP[inicio] != cadenaP[fin]){
        return false;
    }

    // llamada a sí mismo si no  es menor a 1 o si el inicio
    // no es distinto del final para seguir leyendo
    return esPalindromo(cadenaP, inicio + 1, fin -1);
}

// COMPLEJIDAD TEMPORAL
// T(N-2) + 1
// M -> SI SE LIBERA LA MEMORIA HAY QUE TENERLO EN CUENTA. MEMORIA QUE GASTA -> M.
// AL RESOLVER T(N) -> T(N/2) -> LIBERAMOS LAS CONSTANTES -> O(N)