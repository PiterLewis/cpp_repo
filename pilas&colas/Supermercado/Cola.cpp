#include "Cola.h"
#include <iostream>
using namespace std;

// Constructor sin parámetros
Cola::Cola(){
    // al principio están en null.
    this->principio = NULL;
    this->final = NULL;
}

void Cola::encolar(int num){
    // recibe un número y lo coloca al final
    // creamos un nuevo nodo y le pasamos el valor de num
    Nodo* cliente = new Nodo(num);

    // si es el primer nodo, las referencias al siguiente y anterior son nulas
    // de momento estaVacia no está definida pero nos devuelve true o false si hay clientes 
    if(estaVacia()){
        principio = cliente;
        final = cliente;
    } else {
        // desde el nodo al que apunta final, accedemos al puntero siguiente de ese nodo
        final->siguiente = cliente;
        final = cliente;
    }
}

int Cola::desencolar(){
    // devuelve el número que representa el orden
    // de llegada del cliente al supermercado y lo elimina de la lista
    // (Entiendo que también desasignamos el nodo)

    if(estaVacia()){
        cout << "No hay clientes en la cola" << endl;
        return -1; // control de error
    }

    // guardamos un puntero al primer nodo
    Nodo* eliminar = principio;

    // accedemos a su valor y lo guardamos
    int valor = eliminar->valor;

    // avanzamos el puntero al siguiente nodo
    principio = principio->siguiente;

    // si al avanzar el puntero nos devuelve NULL, no quedan más nodos
    if(principio == NULL){
        final = NULL;
    }

    // liberamos el nodo anterior
    delete eliminar;

    return valor;
}

bool Cola::estaVacia(){
    // indica si la cola se encuentra vacía
    // si la referencia al principio de la cola es NULL, entiendo que está vacía
    if(principio == NULL){
        return true;
    }

    return false;
}
