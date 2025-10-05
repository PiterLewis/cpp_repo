#include <iostream>
using namespace std;
void backtrack(int permitidos[], int vacio[], int k, int numEle, int cantidadPermitidos);
int main(){
	int k = 2;
	int permitidos[k] = {1, 2};
	int vacio[k] = {0};
	backtrack(permitidos, vacio, k, 0, 2);
	
	return 0;
}

void backtrack(int permitidos[], int vacio[], int k, int numEle, int cantidadPermitidos){
	
	//caso base: k elementos
	if(numEle == k){
		for(int i = 0; i<k; i++){
			cout << vacio[i] << " ";
		}
		cout << endl;
		return;
	}

	//guardaremos los elementos permutados en vacio
	for(int i = 0; i<cantidadPermitidos; i++){
		vacio[numEle] = permitidos[i];
		backtrack(permitidos, vacio, k, numEle+1, cantidadPermitidos);
	}
}