#include <iostream>
using namespace std;

void swap(int* value, int* value2);
void ordenarArray(int arr1[], int len);
int combinaciones(int arr1[], int len, int valor);

int main(){
	//voraz -> cantidad de pilas y voltaje
	int casosDePrueba;
	cin >> casosDePrueba;
	
	int arrayV[10000];
	int acumulador = 0;
	int solucion = 0;
	
	//solicitar primero las cantidad de pilas y el voltaje
	for(int i = 0; i< casosDePrueba; i++){
		int numPilas;
		int voltaje;
		//fila a leer
		cin >> numPilas;
		//voltaje
		cin >> voltaje;
		
		//cout << "numPilas = " << numPilas << endl;
		//arrayV[numPilas]
		
		for(int j = 0; j< numPilas; j++){
			cin >> arrayV[j];
			
		}
		ordenarArray(arrayV, numPilas);
		solucion = combinaciones(arrayV, numPilas, voltaje);
		cout << solucion << "\n";
		
		
		
		/*for(int k = 0; k<numPilas; k++){
			cout << arrayV[k] << "\t";
		}
		*/
	}	
}

void ordenarArray(int arr1[], int len){
	
	int temp;
	
	for(int i=0; i<len; i++){
		for(int j = 0; j < len - i - 1; j++){
			//mirar si arr1 de j es mayor a j+1
			if(arr1[j] > arr1[j+1]){
				swap(&arr1[j], &arr1[j+1]);
			}
		}
	}
}

void swap(int* value, int* value2){
	int temp;
	temp = *value;
	*value = *value2;
	*value2 = temp;
}

int combinaciones(int arr1[], int len, int valor){
    int inicio = 0;
    int fin = len - 1;
    int solucion = 0;

    while (inicio < fin) {
        if (arr1[inicio] + arr1[fin] >= valor) {
            solucion++;
            fin--;
            inicio++;
        } else {
            inicio++;
        }
    }

    return solucion;
}
