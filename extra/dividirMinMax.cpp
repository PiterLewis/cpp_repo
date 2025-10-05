#include <iostream>
#define MAX_TAM 10
using namespace std;

void max(int x[], int inicio, int final, int &maximo);
int main(){

  
  int n;
  cin >> n; 
  int arr[n];
  for(int i = 0; i<n; i++){
    cin >> arr[i];
  }

  int min, maximo;

  max(arr, 0, n-1, maximo);

  cout << "maximo : " << maximo << endl;

  return 0;
}

void max(int x[], int inicio, int final, int &maximo){

    // caso base: 
    if(inicio == final){
        //hemos llegado al caso base
        maximo = x[inicio];
        return;
    }
    // maximo para la rama izquierda
    int maxIzq, maxDer;
    int mitad = (inicio + final) / 2;
    max(x, inicio, mitad, maxIzq); //dividir y ordenar de 0 a 4
    max(x, mitad + 1, final, maxDer);
   
    if (maxIzq > maxDer) {
        maximo = maxIzq;
    } else {
        maximo = maxDer;
    }
    
}