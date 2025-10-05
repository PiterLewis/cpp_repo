#include <iostream>
using namespace std;

struct Gato{
	string nombre;
	int carisma;
};

Gato devolverGanador(Gato* array, int inicio, int fin, int ronda);
int main(){
	int n;
	cin >> n;
	int ronda = 0;
	//no puedo hacer puntero a struct estatico
	Gato* arrayS = new Gato[n]; //puntero a Gato con gatos nuevos
	for(int i = 0; i<n; i++){
		cin >> arrayS[i].nombre >> arrayS[i].carisma; //leer los datos del gato
	}
	Gato campeon = devolverGanador(arrayS, 0, n - 1, ronda);
	cout << "Campeon Galactico: " << campeon.nombre << endl;
	return 0;
}

Gato devolverGanador(Gato* array, int inicio, int fin, int ronda){
	//ahora si divide y venceras
	//caso base:
	if(inicio == fin){
		//devolver el gato
		return array[inicio];
	}
	
	int mitad = (inicio + fin) / 2;
	Gato ref = devolverGanador(array, inicio, mitad, ronda+1);
	Gato refD = devolverGanador(array, mitad+1, fin, ronda+1);
	
	Gato ganador;
	// condiciones
	if(ronda % 2 == 0){
		ganador = (ref.carisma > refD.carisma) ? ref : refD;
	}else{
		//comparar el nombre
		ganador = (ref.nombre > refD.nombre) ? ref : refD;
	}
	
	cout << "Ronda : " << ronda << "Gato ganador: " << ganador.nombre;
	return ganador;
}