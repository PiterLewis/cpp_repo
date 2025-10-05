#include <iostream>
using namespace std;
#define TAM_MAX 100
int main(){
	//objetos 
	int objetos;
	cin >> objetos;
	int capacidad;
	cin >> capacidad; 
	
	int arrPesos[TAM_MAX];
	int arrValores[TAM_MAX];
	
	for(int i = 0; i< objetos; i++){
		cin >> arrPesos[i];
		cin >> arrValores[i];
	}
	
	//buscar la mejor opción de sumas
	//para programación dinámica hay que crear una MATRIZ
	int matriz[TAM_MAX][TAM_MAX];
	
	//doble for para rellenar la matriz
	for(int i = 1; i<= objetos; i++){
		for(int j = 0; j<= capacidad; j++){
			//objeto que cabe
			if (arrPesos[i-1] > j) {
				matriz[i][j] = matriz[i-1][j];
			} else {
				int sin_meter = matriz[i-1][j];
				int metiendolo = 0;
				
				// Solo si cabe, calculamos metiéndolo
				if (j - arrPesos[i-1] >= 0) {
					metiendolo = matriz[i-1][j - arrPesos[i-1]] + arrValores[i-1];
				}
				
				matriz[i][j] = (sin_meter > metiendolo) ? sin_meter : metiendolo;
			}
		}
	}
	
	
	for(int i = 0; i<= objetos; i++){
		for(int j = 0; j<= capacidad; j++){
		
			cout << matriz[i][j] << " ";
			
		}
		cout << endl;
	}
	

	return 0;
}