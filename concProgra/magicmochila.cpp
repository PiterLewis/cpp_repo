#include <iostream>
using namespace std;

/*Mochila con capacidad 4 y tengo 3 objetos*/
int main(){
	
	int pesos[3] = {1, 3, 2};
	int valores[3] = {15, 20, 10};
	
	/*valor máximo sin pasarme de los 4 kilos*/
	int maxPeso = 4;
	int matriz[4][5] = {0}; //4x4 llena de ceros
	
	for(int i = 1; i< 4; i++){
		for(int j = 0; j<=maxPeso; j++){
			/*recorrer matriz llenandolo con valor de obj o suma*/
			if(pesos[i-1] > j){
				//si el peso del primero es mayor a j, cojo el anterior
				matriz[i][j] = matriz[i-1][j];
			}else{
				/*si no, decido si coger o no coger*/
				int no_meter = matriz[i-1][j]; //el de arriba
				int metiendolo = 0;
				
				if(j - pesos[i-1] >= 0){
					metiendolo = matriz[i-1][j- pesos[i-1]] + valores[i-1];
				}
				
				matriz[i][j] = (no_meter > metiendolo) ? no_meter : metiendolo;
			}
		}
		
	
	}
	
	for(int i = 0; i< 4; i++){
			for(int j = 0; j<=maxPeso; j++){
				cout << matriz[i][j] << " ";
			}
			cout << endl;
		}
	return 0;
}