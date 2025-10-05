#include <iostream>
using namespace std;

//los dragones de enfrentan de dos en dos en cada ronda
//si la ronda es impar, gana el dragón con menor poder
//el proceso se repite hasta que solo quede un dragón: el dragón supremo.
int dragonT(int x[], int inicio, int fin, int ronda);
int main(){
	
	int len;
	cin >> len;
	int x[len];

	for(int i= 0; i<len; i++){
		cin >> x[i]; //rellenar array de numeros
	}
	
	int dragonSupremo = dragonT(x, 0, len - 1, 0);
	cout << "Dragon supremo : " << dragonSupremo;
	
	return 0;
}
int dragonT(int x[], int inicio, int fin, int ronda){
	
	// caso base: queda un dragon
	if(inicio == fin){
		return x[inicio]; //devolvemos el dragón
	}
	
	int medio = (inicio + fin) / 2;
	
	int resIz = dragonT(x, inicio, medio, ronda+1); // es importante en cada llamada aumentar la ronda
	int resD = dragonT(x, medio + 1, fin, ronda+1);
	
	//comparación entre los dos dragones
	int ganador;
    if (ronda % 2 == 0) {
        ganador = (resIz > resD) ? resIz : resD;  // par → gana mayor
    } else {
        ganador = (resIz < resD) ? resIz : resD;  // impar → gana menor
    }
	
	cout << "Ronda " << ronda << ": Gana " << ganador << endl;
	// en vez de tantos returns -> designar una variable ganador y luego retornarla
	
	return ganador;
	
}