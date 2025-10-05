#include <iostream>
using namespace std;
bool sumanN(int vacio[], int k, int n);
void backtrack(int permitidos[], int vacio[], int k, int numEle, int cantidadPermitidos, int n);
int main(){
	int k = 2;
	int permitidos[k] = {1, 2, 3};
	int n = 4;
	int vacio[k] = {0};
	backtrack(permitidos, vacio, k, 0, 3, n);
	
	return 0;
}

void backtrack(int permitidos[], int vacio[], int k, int numEle, int cantidadPermitidos, int n){
	
	//caso base: k elementos y suma = n
	if(numEle == k){
		
		if(sumanN(vacio, k, n)){
			for(int i = 0; i<k; i++){
			cout << vacio[i] << " ";
			}
			cout << endl;
		}
		
		return;
	}

	//guardaremos los elementos permutados en vacio
	for(int i = 0; i<cantidadPermitidos; i++){
		vacio[numEle] = permitidos[i];
		backtrack(permitidos, vacio, k, numEle+1, cantidadPermitidos, n);
	}
	
	/*eliminar duplicados
	for(int i = 0; i < cantidadPermitidos; i++) {
    // Filtro para evitar duplicados: solo si es >= que el anterior
    if (numEle == 0 || permitidos[i] >= vacio[numEle - 1]) {
        vacio[numEle] = permitidos[i];
        backtrack(permitidos, vacio, k, numEle + 1, cantidadPermitidos, n);
    }
	}
	*/
}

bool sumanN(int vacio[], int k, int n){
	int acumm = 0;
	for(int i =0; i<k; i++){
		acumm += vacio[i];
	}
	return(acumm == n);
}