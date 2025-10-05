#include <iostream>
using namespace std;

#define TAM_MAX 10

void imprimirPila(char array[], int tope);
void push(char x, char array[], int tope);
void pop(char array[], int tope);

int main() {
    
    char array[TAM_MAX];
    char aux;
	int tope = -1;
	bool error = false;

	while (cin >> aux) {
		if (aux == '(' || aux == '[') {
			if (tope < TAM_MAX - 1) {
				tope++;
				push(aux, array, tope);
			}
		} else if (aux == ')' || aux == ']') {
			if (tope == -1) {
				error = true;
				break;
			}
			char cima = array[tope];
			if ((aux == ')' && cima != '(') || (aux == ']' && cima != '[')) {
				error = true;
				break;
			} else {
				pop(array, tope);
				tope--;
			}
		}
	}
	
	if (error || tope != -1) {
		cout << "❌ Expresión no balanceada" << endl;
	} else {
		cout << "✅ Expresión balanceada" << endl;
	}
	cout << "STACK : ";
	for(int i = 0; i< TAM_MAX; i++){
		cout << array[i] << " ";
	}
	
	/* AHORA QUE ESTÁ BIEN APILADO, HAY QUE COMPROBAR */
	
	
	
    return 0;
}

void imprimirPila(char array[], int tope) {
    for (int i = 0; i <= tope; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void push(char x, char array[], int tope) {
    array[tope] = x;
}

void pop(int array[], int tope) {
    array[tope] = 0;
}

