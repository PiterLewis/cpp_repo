/*
*  @author Santiago Garcia
*  @date 15/03/2025
*  
*/

#include <iostream>
using namespace std;
#include "ListaEnlazada.h"
#include "Nodo.h"
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

//constructor por parámetros
ListaEnlazada::ListaEnlazada() {
    //inicializamos el puntero al primer nodo como NULL
    lista = NULL;
    //inicializamos la longitud de la lista en 0
    n = 0;
}

//destructor
ListaEnlazada::~ListaEnlazada() {
    //liberar memoria del vector
    Nodo* actual = lista;
    while (actual != NULL) {
        Nodo* siguiente = actual->siguienteNodo;
        delete actual;
        actual = siguiente;
    }
}

//metodo permite obtener el nodo de la lista en pos
Nodo* ListaEnlazada::getNodo(int pos) {
    //la posición debe estar dentro de los límites válidos
    assertdomjudge(pos >= 0 && pos < n);

    //creamos un puntero auxiliar
    Nodo* aux = lista;
    //recorremos la lista hasta llegar a la posición deseada
    for (int i = 0; i < pos; i++) {
        aux = aux->siguienteNodo;
    }
    //retornamos el nodo en la posición pos
    return aux;
}

//metodo permite obtener el valor de un nodo en pos
int ListaEnlazada::getValor(int pos) {
    //la posición debe estar dentro de los límites válidos
    assertdomjudge(pos >= 0 && pos < n);

    //otenemos el nodo en la posición pos
    Nodo* aux = getNodo(pos);
    //retornamos valor del nodo
    return aux->elemento;
}

//metodo que permite modificar el valor de un nodo
void ListaEnlazada::setValor(int pos, int nuevoValor) {
    //la posición debe estar dentro de los límites válidos
    assertdomjudge(pos >= 0 && pos < n);

    //obtenemos el nodo en la posición pos
    Nodo* aux = getNodo(pos);
    // Modificamos el valor del nodo
    aux->elemento = nuevoValor;
}

//metodo que permite obtener la longitud de la lista
int ListaEnlazada::getN() {
    //devolvemos la longitud de la lista
    return n;
}

//metodo que permite insertar un nodo en la posición pos
void ListaEnlazada::insertar(int pos, int nuevoValor) {
    //la posición debe estar dentro de los límites válidos
    assertdomjudge(pos >= 0 && pos <= n); 
    //creamos un nuevo nodo
    Nodo* nuevoNodo = new Nodo;
    //asignamos el valor al nuevo nodo
    nuevoNodo->elemento = nuevoValor;

    //si la lista está vacía
    if (lista == NULL) {
        //el nuevo nodo será el primer nodo de la lista
        lista = nuevoNodo;
        //el siguiente nodo del nuevo nodo será NULL
        nuevoNodo->siguienteNodo = NULL;
    } else {
        //si la posición es 0
        if (pos == 0) {
            //el nuevo nodo será el primer nodo de la lista
            nuevoNodo->siguienteNodo = lista;
            lista = nuevoNodo;
        } else {
            //obtenemos el nodo anterior a la posición pos
            Nodo* anterior = getNodo(pos - 1);
            //el siguiente nodo del nuevo nodo será el nodo en la posición pos
            nuevoNodo->siguienteNodo = anterior->siguienteNodo;
            //el siguiente nodo del nodo anterior será el nuevo nodo
            anterior->siguienteNodo = nuevoNodo;
        }
    }
    //incrementamos la longitud de la lista
    n++;
}

//metodo que permite eliminar un nodo en la posición pos
void ListaEnlazada::eliminar(int pos) {
    //la posición debe estar dentro de los límites válidos
    assertdomjudge(pos >= 0 && pos < n);

    //si la lista no está vacía
    if (lista != NULL) {
        //si la posición es 0
        if (pos == 0) {
            //creamos un nodo auxiliar
            Nodo* aux = lista;
            //el primer nodo de la lista será el siguiente nodo del primer nodo
            lista = lista->siguienteNodo;
            //liberamos la memoria del nodo eliminado
            delete aux;
        } else {
            //obtenemos el nodo anterior a la posición pos
            Nodo* anterior = getNodo(pos - 1);
            // Creamos un nodo auxiliar
            Nodo* aux = anterior->siguienteNodo;
            //el siguiente nodo del nodo anterior será el siguiente nodo del nodo en la posición pos
            anterior->siguienteNodo = aux->siguienteNodo;
            //liberamos la memoria del nodo eliminado
            delete aux;
        }
        //decrementamos la longitud de la lista
        n--;
    }
}

//concatenar una lista con la lista actual
void ListaEnlazada::concatenar(ListaEnlazada* listaAConcatenar) {
    //La lista a concatenar no debe ser nullptr
    assertdomjudge(listaAConcatenar != nullptr);

    //si la lista a concatenar no está vacía
    if (listaAConcatenar->getN() > 0) {
        //si la lista actual está vacía
        if (n == 0) {
            //la lista actual será la lista a concatenar
            lista = listaAConcatenar->lista;
        } else {
            //obtenemos el último nodo de la lista actual
            Nodo* aux = lista;
            while (aux->siguienteNodo != NULL) {
                aux = aux->siguienteNodo;
            }
            //el siguiente nodo del último nodo de la lista actual será el primer nodo de la lista a concatenar
            aux->siguienteNodo = listaAConcatenar->lista;
        }
        //la longitud de la lista actual será la suma de la longitud de la lista actual y la longitud de la lista a concatenar
        n += listaAConcatenar->getN();
        //la lista a concatenar será vacía
        listaAConcatenar->lista = NULL;
        //la longitud de la lista a concatenar será 0
        listaAConcatenar->n = 0;
    }
}

//metodo que permite buscar un valor en la lista
int ListaEnlazada::buscar(int elementoABuscar) {
    //creamos un puntero auxiliar
    Nodo* aux = lista;
    //recorremos la lista
    for (int i = 0; i < n; i++) {
        //si el valor del nodo es igual al valor buscado
        if (aux->elemento == elementoABuscar) {
            //retornamos la posición del nodo
            return i;
        }
        //avanzamos al siguiente nodo
        aux = aux->siguienteNodo;
    }
    //si el valor no se encuentra en la lista
    return -1;
}