#include <iostream>
using namespace std;

// Algoritmo recursivo que utilizando divide y vencerás
// devuelve la suma de todos los el positivos de un array de enteros
int divideYvenceras(int x[], int inicio, int fin);
int main(){
	
	int len;
	cin >> len;
	int x[len];
	
	for(int i= 0; i< len; i++){
		cin >> x[i];
	}
	
	int resultado = divideYvenceras(x, 0, len - 1);
	cout << "Resultado final : " << resultado;
	return 0;
}

int divideYvenceras(int x[], int inicio, int fin){
	int aux = 0;
	//caso base: devolver numero
	if(inicio == fin){
		// sumamos a aux si es positive
		if(x[inicio] > 0){
			aux += x[inicio];
		}
		return aux;
	}
	
	int mitad = (inicio + fin) / 2;
	
	int resIzquierda = divideYvenceras(x, inicio, mitad);
	int resDerecha = divideYvenceras(x, mitad + 1, fin);
	
	return resIzquierda + resDerecha;
}