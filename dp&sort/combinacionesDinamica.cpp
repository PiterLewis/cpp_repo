/*
Autor : Santiago García Domínguez
2ºINSO A
Fecha : 17/02/2025.
*/
#include <iostream>
#define TAM_MAX 10
using namespace std;

// generar el triangulo con las dimensiones estaticas
void trianguloPascal(int dimensiones[TAM_MAX + 1][TAM_MAX + 1]);

int main() {
    int n, r;
    //inicializamos la matriz entera a 0 que si no sumaremos valores
    //basura cuando accedamos a posiciones no deseadas
    int dimensiones[TAM_MAX + 1][TAM_MAX + 1] = {0}; 
    //generamos el triangulo de tartaglia o pascal con 11 x 11.
    trianguloPascal(dimensiones);

    
    /*
    imprimimos para debugging
    for (int i = 0; i <= TAM_MAX; i++) {
        //si hacemos que j <= i, se imprimira n numeros dependiendo
        //del numero de las filas.
        for (int j = 0; j <= i; j++) {
            cout << dimensiones[i][j] << " ";
        }
        cout << endl;
    }
    */

   //reciclado de codigo factorial
    do {
        cin >> n;
        cin >> r;

        // si n es negativo, terminar el programa
        if (n < 0) {
            return 0;
        }
        // si r es mayor que n o r es negativo printear "ERROR"
        else if (r > n || r < 0) {
            cout << "ERROR" << endl;
        }
        // si n y r están dentro del rango, usar el triángulo
        else if (n <= TAM_MAX && r <= TAM_MAX) {
            cout << dimensiones[n][r] << endl;
        }
        // si n o r están fuera del rango, mostrar "ERROR"
        else {
            cout << "ERROR" << endl;
        }
    }while (true);

    return 0;
}

//lo mismo que arriba
void trianguloPascal(int dimensiones[TAM_MAX + 1][TAM_MAX + 1]) {
    //la primera fila la inicializamos con 1 para poder sumar despues
    dimensiones[0][0] = 1;

    // rellenamos el triangulo
    for (int i = 1; i <= TAM_MAX; i++) {
        dimensiones[i][0] = 1; // el primer elemento de cada fila es 1
        for (int j = 1; j <= i; j++) {
            //hacemos la suma de el de "arriba a la izq" y "arriba a la derecha"
            //puesto que ellos estan en 1 fila antes y una columna antes (izq) y una fila antes misma col(derecha)
            dimensiones[i][j] = dimensiones[i - 1][j - 1] + dimensiones[i - 1][j];
        }
    }
}