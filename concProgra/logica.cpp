//nivel 1 logica de programacion
#include <iostream>
using namespace std;
int main(){
	int n;
	cin >>n;
	int array[n];
	for(int i = 0; i < n; i++){
		cin >> array[i];
	}

	int flagsPosicion[n] = {0};
	
	//encontrar valor más grande y hacer conteo de 
	//veces que aparece un número
	int mayor = 0;
	for(int i = 0; i < n; i++){
		if(array[i] > mayor){
			//el mayor pasa a ser el valor
			mayor = array[i];
		}
	}
	
	int contador = 0;
	for(int i = 0; i < n; i++){
		int valor = array[i];
		for(int j = 0; j<n; j++){
			//si encontramos varias veces valor, sumamos el contador
			if(valor == array[j]){
				contador++;
			}
		}
		flagsPosicion[i] = contador; //flags
		contador = 0; //reset 
	}
	
	for(int i = 0; i < n; i++){
		cout << "VALORES : " << flagsPosicion[i];
	}
	cout << "MAXIMO : " << mayor;
	
	int masRepetidoPos = 0;
	for(int i = 0; i < n; i++){
		if(flagsPosicion[i] > masRepetidoPos){
			masRepetidoPos = i; //la posicion del más repetido
		}
	}
	
	cout << "EL MÁS REPETIDO : " << array[masRepetidoPos];
}