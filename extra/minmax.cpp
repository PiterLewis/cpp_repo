#include <iostream>
#define MAX_TAM 10
using namespace std;

void minmax(int x[], int n, int &min, int &max);
int main(){

  int arr[] = {3,1,5,2,6,7,9,12};
  int n = sizeof(arr) / sizeof(arr[0]);
  int min, max;

  minmax(arr, n, min, max);

  cout << "Minimo : " << min << endl;
  cout << "maximo : " << max << endl;

  return 0;
}

void minmax(int x[], int n, int &min, int &max){

    //recursivo encontrar max y min
    if(n == 1){
        cout << "Caso base alcanzado con x[0] = " << x[0] << " min = " << min << ", max = " << max << endl;
        min = max = x[0];
        return ;
    }

    cout << "trampoliiin" << endl;
    minmax(x, n-1, min, max);
    cout << "trampolin comparadooor" << endl;
    if(x[n-1] < min)
        min = x[n-1];
    if(x[n-1] > max)
        max = x[n-1];
    
    cout << "Despues de comparar x[" << n-1 << "]  min = " << min << ", max = " << max  << endl;
}