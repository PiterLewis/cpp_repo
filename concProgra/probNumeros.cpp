#include <iostream>
using namespace std;

bool sonSuma(int numero, int x[], int tam);
bool backtrack(int numero, int x[], int tam);
// programa combinaciones numeros
int main(){
	
	int num;
	cin >> num;
	
	int x[num] = {0}; //PRO TIP
	int tam = num;
	if(!backtrack(num, x, 0)){
		cout << "conseguido";
	}else{
		cout << "no alcanzable";
	}
	return 0;
}

bool backtrack(int numero, int x[], int tam){
	
	//caso base: llegamos a numero
	if(sonSuma(numero, x, tam)){
		for(int i = 0; i<tam; i++){
			if(x[i] != 0){
				cout << x[i] << " ";
			}
			
		}
		cout << endl;
		return true;
	}
	
	//permutaciones
	//bucle llamando a backtrack metiendole en el array los numeros 
	//de 1 hasta que se cumpla
	for(int i = 1; i<numero; i++){
		x[tam] = i;
		bool res = backtrack(numero, x, tam+1);  
		if(res){break;}
	}
	
	return false;
	
}

bool sonSuma(int numero, int x[], int tam){
	
	int acumulador = 0;
	for(int i =0; i<tam; i++){
		acumulador += x[i];
	}
	
	return (acumulador == numero); //if pro tip  
}