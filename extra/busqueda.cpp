#include <iostream>
using namespace std;



/*Divide y vencerás programa busqueda binaria*/
int busquedaBinaria(int arr[], int izquierda, int derecha, int x);
int main(){

    // dentro de estos numeros hay que encontrar con divide y venceras
    int arr1[] = {1,3,5,7,9,11};
    int x;
    int izquierda = 0;
    int derecha = sizeof(arr1) / sizeof(arr1[0] - 1);
    cin >> x;

    int resultado = busquedaBinaria(arr1, izquierda, derecha, x);
    cout << "El número " << x << " está en la posición: " << resultado << endl;
}

int busquedaBinaria(int arr[], int izquierda, int derecha, int x){
    if(izquierda > derecha){
        return -1; // no encontramos el numero
    }

    int mid = (izquierda + derecha) / 2;

    if(arr[mid] == x){
        return mid;
    }else if(arr[mid] > x){
        return busquedaBinaria(arr, izquierda, mid -1, x);

    }else{
        return busquedaBinaria(arr, mid + 1, derecha, x);
    
    }

}
