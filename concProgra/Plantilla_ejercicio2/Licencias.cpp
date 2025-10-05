#include "Licencias.h"
#include "Licencia.h"
#include <iostream>

using namespace std;

Licencias::Licencias(int capacidad) {
	this->n = 0;
	this->capacidad = capacidad;
	this->tabla = NULL;
}

int Licencias::obtenerPosicion (long dni) {
	//funcion hash
	int dato = dni % (this->capacidad); //resto division entre capacidad.
	return dato;
}

void Licencias::insertarLicencia (long codigo, string herramienta) {
	//para implementar la licencia
	int posicion = obtenerPosicion(codigo);
	//teniendo ya la posición con el hash, dentro de la tabla metemos la licencia
	
	//ref a lista
	Nodo *refAtabla = this->tabla->lista;
	//bucle para recorrer lista y encontrar la posición ideal
	for(int i = 0; i<posicion; i++){
		refAtabla = refAtabla->lista; //iteramos para elegir la lista correcta en la que
	}
	
	Nodo* refN;
	Licencia* ref;
	ref->codigo = codigo;
	ref->herramienta = herramienta;
	
	refN->elemento = ref;
	//nodo con ya la licencia insertada
	
	
	Nodo* referencia = refAtabla;
	//si no hay un nodo, la licencia va al principio
	if(refAtabla->lista == NULL){
		//asignar a la lista el nodo con la ref
		refAtabla->lista = refN;
	}else
	{
		//si hay nodos en la lista, hay que meterlos después
		do{
			referencia = referencia->siguienteNodo; //ahora ya tenemos el hueco libre
		}while(referencia != NULL); //mientras que la ref no llegue al fin
	}
	
	//asignamos a la referencia el nodo con los datos
	referencia = refN;
	referencia -> siguienteNodo = NULL; //ponemos el nodo siguiente a null para indicar fin de lista
	

}

void Licencias::eliminarLicencia (long codigo) {
	
	//pillar la lista con el hash
	int posicion = obtenerPosicion(codigo);
	
	//ref a tabla
	ListaEnlazada *refAtabla = this->tabla;
	//bucle para recorrer lista y encontrar la posición ideal
	for(int i = 0; i<posicion; i++){
		refAtabla = refAtabla->lista; //iteramos para elegir la lista correcta en la que
	}
	
	Nodo* referencia = refAtabla; //para seguir los nodos en la lista
	//si no hay nodos en la lista, está vacía
	if(refAtabla->lista == NULL){
		cout << "La lista está vacía";
		
	}else{
		//si hay nodos, los recorremos
		while(referencia->elemento->codigo != codigo){
			referencia = referencia->siguienteNodo; //pillamos el nodo final
		}
	}
	
	delete referencia; 
	
}

void Licencias::imprimir() {
	cout << endl;
	for (int i=0; i<capacidad; i++) {
		cout << "P" << i << ": ";
		this->tabla[i].imprimir();
	}
}
