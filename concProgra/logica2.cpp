#include <iostream>
using namespace std;

/*Dado un número n, 
  imprimir todos los pares tal que a + b = n 
*/

int main(){
	int k;
	cin >> k;
	int n;
	cin >> n;
	
	int array[n];
	for(int i = 0; i<n; i++) {
		cin >> array[i]; //guardamos
	}
	
	//números pares del array que suman N
	int aux[n] = {0}; //array de 0s
	int cont = 0;
	for(int i = 0; i<n; i++) {
		if(array[i] % 2 == 0){
			//los pares los guardamos en un array
			aux[cont] = array[i];
			cont++; //incrementamos la i del array
		}
	}
	
	//permutaciones del array de pares
	int inicio = 0;
	int fin = cont-1;
	/*while(inicio < fin){
		if(aux[inicio] + aux[fin] == k){
			cout << "COMBINACION : " << aux[inicio] << " y " << aux[fin];
			cout << endl;
		} 
		inicio++;
		fin --;
	}*/
	
	for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {  // j = i para evitar pares repetidos
            if (array[i] + array[j] == k && array[i] <= array[j]) {
				cout << "COMBINACION : " << array[i] << " y " << array[j] << endl;
			}

        }
    }

}