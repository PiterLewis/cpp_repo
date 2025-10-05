#include <iostream>
#define N_TIPO_CENTRALES 5
/*ESTA PERFECTO*/
using namespace std;
bool cumplenReq(char aux[N_TIPO_CENTRALES], int n, int r);
void backtrack(char tipo_centrales[N_TIPO_CENTRALES], int n, int r, int elementosIniciales, char aux[N_TIPO_CENTRALES]);
int main(){
	
	char tipo_centrales[N_TIPO_CENTRALES] = {'E', 'S', 'H', 'N', 'T'}; //tipos centrales
	int n; // el n
	int r; // r restrict
	cin >> n;
	cin >> r;
	int elementosIniciales = 0;
	char aux[N_TIPO_CENTRALES]; //array para auxiliares
	
	backtrack(tipo_centrales, n, r, elementosIniciales, aux);
	
}
void backtrack(char tipo_centrales[N_TIPO_CENTRALES], int n, int r, int elementosIniciales, char aux[N_TIPO_CENTRALES]){
	
	//si el array llega a contener n digitos, se imprime
	if(n == elementosIniciales){
		if(cumplenReq(aux, n, r)){
			for(int i=0; i<n; i++){
				cout <<aux[i]; //imprimimos el array con las centrales nucleares
				//solo si cumplen la condición de las factorias
			}
			cout << endl;
		}
		return;
		
	}
	
	
	
	//comprobar si cumple con la r
	for(int i = 0; i<N_TIPO_CENTRALES; i++){
		aux[elementosIniciales] = tipo_centrales[i]; //vamos añadiendo al auxiliar los elementos
		//llamada recursiva a la función
		backtrack(tipo_centrales, n, r,elementosIniciales+1, aux);
	}
}

bool cumplenReq(char aux[N_TIPO_CENTRALES], int n, int r){
	
	//función booleana para ver si cumple con los requisitos de tener
	// R centrales buenas
	int contador = 0;
	for(int i=0; i<N_TIPO_CENTRALES; i++){
		if(aux[i] == 'E' || aux[i] == 'S' || aux[i] == 'H'){
			
			contador++;
		}
	}
	
	//si contador es igual a r, se cumplen las condiciones
	if(contador == r){
		return true;
	}else{ 
		return false;
	}
}