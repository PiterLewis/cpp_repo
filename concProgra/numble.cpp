#include <iostream>
using namespace std;

bool sonSuma(int numero, int x[], int tam);
bool backtrack(int numero, int x[], int tam);

int main(){
	
	//array de 4 numeros
	int x[4];
	for(int i = 0; i<4; i++){
		cin >> x[i];
	}
	int num;
	cin >> num;
	
	if(!backtrack(num, x, 4)){
		cout << "conseguido";
	}else{
		cout << "no alcanzable";
	}
	return 0;
}

bool backtrack(int numero, int x[], int tam){
	
	if(sonSuma(numero, x, tam)){
		for(int i = 0; i< 4; i++){
			cout << x[i] << " ";
		}
		cout << endl;
		return true;
	}
	
	//permutaciones, si leemos un -1 permutamos el numero
	for(int i =0; i<numero; i++){
		if(x[i] == -1){
			//permutamos -1
			for(int j = 0; j<10; j++){
				x[i] = j;
				bool res = backtrack(numero, x, tam);  
			}
			x[i] = -1;
			break;
		}
	}
	return false;
}
bool sonSuma(int numero, int x[], int tam){
	
	int acumulador = 0;
	for(int i =0; i<tam; i++){
		if(x[i] != -1){
			acumulador += x[i];
		}else{
			return false;
		}
	}
	
	return (acumulador == numero); //if pro tip  
}
