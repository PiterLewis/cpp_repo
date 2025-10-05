#include <iostream>
using namespace std;
//suma maxima de una sublista contigua de un array de numeros enteros
int divideYvenceras(int x[], int inicio, int fin);
int main(){
	
	int len;
	cin >> len;
	int x[len];
	
	for(int i= 0; i< len; i++){
		cin >> x[i];
	}
}

int maxSubarray(int arr[], int inicio, int fin) {
    // Caso base: un solo elemento
    if (inicio == fin) {
        return arr[inicio];
    }

    int medio = (inicio + fin) / 2;

    // Parte izquierda
    int maxIzquierda = maxSubarray(arr, inicio, medio);

    // Parte derecha
    int maxDerecha = maxSubarray(arr, medio + 1, fin);

    // Parte cruzando el medio
    int maxCruzado = maxCruzando(arr, inicio, medio, fin);

    // Resultado: el mayor de los tres
    return max({maxIzquierda, maxDerecha, maxCruzado});
}

int maxCruzando(int arr[], int inicio, int medio, int fin) {
    // Buscar la mejor suma hacia la izquierda desde el medio
    int sumaIzq = 0;
    int maxIzq = arr[medio];
    sumaIzq = 0;
    for (int i = medio; i >= inicio; i--) {
        sumaIzq += arr[i];
        if (sumaIzq > maxIzq)
            maxIzq = sumaIzq;
    }

    // Buscar la mejor suma hacia la derecha desde medio + 1
    int sumaDer = 0;
    int maxDer = arr[medio + 1];
    sumaDer = 0;
    for (int i = medio + 1; i <= fin; i++) {
        sumaDer += arr[i];
        if (sumaDer > maxDer)
            maxDer = sumaDer;
    }

    // El mejor cruce incluye ambos lados
    return maxIzq + maxDer;
}
