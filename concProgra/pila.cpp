#include <iostream>
using namespace std;

#define TAM_MAX 10

void imprimirPila(int array[], int tope);
void push(int x, int array[], int tope);
void pop(int array[], int tope);

int main() {
    char opcion;
    int array[TAM_MAX];
    int tope = -1;
    int elemento = 0;

    while (true) {
        cin >> opcion;
        switch (opcion) {
            case 'I':
                imprimirPila(array, tope);
                break;
            case 'P':
                cin >> elemento;
                if (tope < TAM_MAX - 1) {
                    tope++;
                    push(elemento, array, tope);
                } else {
                    cout << "La pila está llena" << endl;
                }
                break;
            case 'O':
                if (tope >= 0) {
                    pop(array, tope);
                    tope--;
                } else {
                    cout << "La pila está vacía" << endl;
                }
                break;
        }
    }

    return 0;
}

void imprimirPila(int array[], int tope) {
    for (int i = 0; i <= tope; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void push(int x, int array[], int tope) {
    array[tope] = x;
}

void pop(int array[], int tope) {
    array[tope] = 0;
}
