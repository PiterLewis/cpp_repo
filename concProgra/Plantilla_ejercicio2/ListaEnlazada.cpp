#include "ListaEnlazada.h"
#include<stdlib.h>
#include <iostream>
using namespace std;

Nodo * ListaEnlazada::getNodo (int posicion) {
	//la ref a nodo la igualamos al inicio de la lista
	Nodo* aux= lista;
	for(int i = 0; i<posicion; i++){
		//recorremos la lista hasta pos y devolvemos nodo
		aux = aux->siguienteNodo;
	}
	
	return aux;
}

ListaEnlazada::ListaEnlazada() {
	
	this->lista = NULL; //ptr comienza en null
	this-> n = 0; //comienza en 0 la n
	
}

Licencia ListaEnlazada::getValor(int posicion) {
	//llamamos a que nos den el nodo
	Nodo* aux = getNodo(posicion); //ref
	return aux->elemento; //devolvemos el objeto de tipo licencia
}

void ListaEnlazada::setValor(int posicion, Licencia nuevoValor) {
	Nodo* aux = getNodo(posicion); //pillamos la ref al nodo
	aux->licencia = nuevoValor; //le seteamos el objeto licencia.
	
}

int ListaEnlazada::getN() {
	return this->n;
}

void ListaEnlazada::insertar (int posicion, Licencia nuevoValor) {
	
	
	//crear objeto de tipo listaEnlazada
	ListaEnlazada *ref = this->tabla;
	
	
	Nodo* aux;
	aux -> elemento = nuevoValor;
	//si la lista está vacia, el nodo va al principio
	if(ref == NULL){
		ref->lista = aux; //asignamos nodo
	}else{
		while(ref != NULL){
			ref = ref->siguienteNodo; //nodo mas afuera
		}
	}
	ref = aux;
	this->n = n+1;
}


void ListaEnlazada::eliminar (int posicion) {
	
	//crear objeto de tipo listaEnlazada
	ListaEnlazada *ref = this->tabla;
	
	Nodo* ref = getNodo(posicion);
	//pillamos referencia al nodo
	//lo eliminamos
	
	if(ref -> siguienteNodo == NULL){
		delete ref;
	}
	
	
	this->n = n-1;
}

int ListaEnlazada::buscar(Licencia elementoABuscar) {
	
	//ponemos ref al inicio de la lista
	Nodo* ref = this->lista;
	
	int pos = 0;
	while(ref->elemento != elementoABuscar){
		ref = ref->siguienteNodo;
		pos++;
	}
	
	//devuelvo la posición
	return pos;
}

void ListaEnlazada::imprimir(){

	cout << "n=" << this->n << " | contenido=";
	Nodo* nodoActual = this->lista;
	for(int i = 0; i < this->n; i++){
		cout << "(" << nodoActual->elemento.codigo << ", " << nodoActual->elemento.herramienta << ") ";
		nodoActual = nodoActual->siguienteNodo;
	} 
	cout << endl;
}

ListaEnlazada::~ListaEnlazada() {
	delete lista; //eliminar la anidación de nodos
}



