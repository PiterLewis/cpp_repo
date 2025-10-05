#include<iostream>
#include"ListaCircular.h"
using namespace std;

/*Implementamos toda la clase Lista Circular*/

// Constructor sin parametros
ListaCircular::ListaCircular(){
    //inicializamos el primer nodo a null
    this->lista = NULL;
    this->n = 0;
}

void ListaCircular::insertar(int pos, string s){
    
    //precondicion por si acaso.    
    if (pos < 0 || pos > n) {
        cout << "Posición invalida" << endl;
        return;
    }
    
    //introduce el string s en la posicion pos de la lista
    //creamos nuevo nodo
    Nodo* nuevo = new Nodo; 
    nuevo->elemento = s;

    if(this->n == 0){
        //la lista está vacía, pero es doblemente enlazada asiq apunta a sí mismo.
        nuevo->siguienteNodo = nuevo;
        nuevo->anteriorNodo = nuevo;
        lista = nuevo;
    }else if(pos == n){
        // insertar al final: cogemos el primero (lista), y vamos al último con ->anterior
        Nodo* aLista = lista;
        Nodo* anterior = aLista->anteriorNodo;
    
        nuevo->siguienteNodo = aLista; // el siguiente del nuevo es el primero
        nuevo->anteriorNodo = anterior; // el anterior del nuevo es el último
    
        anterior->siguienteNodo = nuevo;
        aLista->anteriorNodo = nuevo;
        
    }else{
        // caso normal (inserción en medio o al principio, ya controlado)
        Nodo* aLista = getNodo(pos); 
        Nodo* anterior = aLista->anteriorNodo;
    
        nuevo->siguienteNodo = aLista;
        nuevo->anteriorNodo = anterior;
    
        anterior->siguienteNodo = nuevo;
        aLista->anteriorNodo = nuevo;
    
        if (pos == 0) {
            lista = nuevo;
        }
    }
    n++;
}    


void ListaCircular::eliminar(int pos){

    //precondición: si la posición es negativa o mayor que el último índice
    if(pos < 0 || pos >= n){
        cout << "Posición no válida" << endl;
        return;
    }

    //caso especial: si solo hay un nodo en la lista
    if(n == 1){
        //lo eliminamos directamente
        delete lista;
        lista = NULL;
        n = 0;
        return;
    }

    //usamos getNodo para llegar al nodo que queremos eliminar
    Nodo* eliminar = getNodo(pos);

    //pillamos las referencias al nodo anterior y al siguiente del que vamos a eliminar
    Nodo* refA = eliminar->anteriorNodo;
    Nodo* refS = eliminar->siguienteNodo;

    //ajustamos los punteros: el anterior ahora apunta al siguiente, saltándose el eliminado
    refA->siguienteNodo = refS;
    refS->anteriorNodo = refA;

    //si eliminamos el nodo al que apunta lista, lista tiene que apuntar al siguiente
    if(eliminar == lista){
        lista = refS;
    }

    //eliminamos el nodo de la memoria
    delete eliminar;

    //actualizamos el número de nodos
    n--;
}


void ListaCircular::girar(int g){
    // gira todos los elementos hacia la izquierda o hacia la derecha 
    // (izq -> negativo, der -> positivo)

    //si no giramos na, salimos directamente
    if (g == 0 || lista == NULL || n == 0) {
        return;
    }

    Nodo* refInicial = lista;

    if(g > 0){
        // girar a la derecha
        for(int i = 0; i < g; i++){
            refInicial = refInicial->siguienteNodo; // avanzamos a siguiente nodo
        }
        lista = refInicial; // actualizamos la referencia del puntero a lista

    } else {
        g = -g; // cambiamos el signo pa hacerlo positivo
        for(int i = 0; i < g; i++){
            refInicial = refInicial->anteriorNodo; // ahora nos vamos pa atrás
        }
        lista = refInicial; // actualizamos la lista al nuevo nodo actual
    }
}


//funcion privada que devuelve el puntero al nodo en la posición pos
Nodo* ListaCircular::getNodo(int pos) {
    //control de errores, si la posición no existe, devolvemos nullptr
    if (pos < 0 || pos >= n) {
        return nullptr;
    }

    Nodo* actual = lista;
    //recorremos hasta llegar a la posición
    for (int i = 0; i < pos; i++) {
        actual = actual->siguienteNodo;
    }

    return actual;
}


string ListaCircular::getValor(int pos) {
    Nodo* nodo = getNodo(pos); //usamos getNodo en vez de bucles

    if (nodo != NULL) {
        return nodo->elemento;
    } else {
        return "no válido"; //nos quejamos
    }
}


void ListaCircular::setValor(int pos, string nuevoValor) {
    Nodo* nodo = getNodo(pos); //pillamos el nodo en esa posición

    if (nodo != nullptr) {
        nodo->elemento = nuevoValor; //actualizamos el valor
    }
}

ListaCircular::~ListaCircular(){
    //si la lista está vacía, no hacemos nada
    if (lista == NULL || n == 0) {
        return;
    }

    Nodo* actual = lista;
    Nodo* siguiente = nullptr;

    //vamos a eliminar n nodos exactamente (sabemos cuántos hay)
    for (int i = 0; i < n; i++) {
        //guardamos el siguiente nodo para no perder la referencia
        siguiente = actual->siguienteNodo;

        //eliminamos el actual
        delete actual;

        //avanzamos
        actual = siguiente;
    }

    //finalmente dejamos todo limpio
    lista = NULL;
    n = 0;
}

int ListaCircular::getN() {
    return n;
}
