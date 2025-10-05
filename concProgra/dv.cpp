#include <iostream>
using namespace std;
//programa divide y vencerás
//PASOS:
// dividir el problema es subpartes
// resolver cuando se tenga el minimo de subpartes
// combinar la solucion parcial
//ejercicio propuesto: 
//implementa un algoritmo recursivo para encontrar el número de veces que 
//aparece un valor específico en un array de enteros usando divide y vencerás

int divideVenceras(int x[], int inicio, int fin, int numeroBuscado);

int main(){
	
	
	int len;
	cin >> len;
	int x[len];
	
	for(int i= 0; i< len; i++){
		cin >> x[i];
	}
	
	int numeroBuscado;
	cin >> numeroBuscado;
	
	int resultado = divideVenceras(x, 0, len-1, numeroBuscado);
	cout << "Aparece : " << resultado << " veces";
	return 0;
}

int divideVenceras(int x[], int inicio, int fin, int numeroBuscado){
    int contador = 0;

    // Verificación de seguridad
    if (inicio > fin) return 0;

    // Caso base
    if(inicio == fin){
        if(x[inicio] == numeroBuscado){
            contador++;
        }
        return contador;
    }

    int medio = (inicio + fin) / 2;

    // Dividir el array en dos mitades
    int izquierda = divideVenceras(x, inicio, medio, numeroBuscado);
    int derecha = divideVenceras(x, medio + 1, fin, numeroBuscado);

    // Combinar resultados
    contador = izquierda + derecha;

    return contador;
}
