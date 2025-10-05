/*
*  @author Santiago Garcia
*  @date 15/03/2025
*/

#include "ListaEnlazada.h"
#include "assertdomjudge.h"
#include <iostream>

//crea la lista vacia con n en 0 y punteros en null
ListaEnlazada::ListaEnlazada() {
    lista = nullptr;
    n = 0;
    posicionUltimoNodoAccedido = -1;
    punteroUltimoNodoAccedido = nullptr;
}

//borra todos los nodos recorriendo la lista uno por uno
ListaEnlazada::~ListaEnlazada() {
    Nodo* aux = lista;
    while (aux != nullptr) {
        Nodo* siguiente = aux->siguienteNodo;
        delete aux;
        aux = siguiente;
    }
}

//devuelve el nodo en la posicion indicada, usa los punteros de la lista para getnodo
//si ya se accedio a una posicion cercana antes, empieza desde ahi
Nodo* ListaEnlazada::getNodo(int posicion) {
    assertdomjudge(posicion >= 0 && posicion < n);
    assertdomjudge(n > 0);

    Nodo* actual;
    int inicio;

    if (posicionUltimoNodoAccedido != -1 && punteroUltimoNodoAccedido != nullptr &&
        posicionUltimoNodoAccedido <= posicion) {
        actual = punteroUltimoNodoAccedido;
        inicio = posicionUltimoNodoAccedido;
    } else {
        actual = lista;
        inicio = 0;
    }

    for (int i = inicio; i < posicion; ++i) {
        actual = actual->siguienteNodo;
    }

    posicionUltimoNodoAccedido = posicion;
    punteroUltimoNodoAccedido = actual;

    return actual;
}

//devuelve el contacto de la posicion usando getnodo
Contacto ListaEnlazada::getValor(int posicion) {
    assertdomjudge(posicion >= 0 && posicion < n);
    assertdomjudge(n > 0);
    Nodo* nodoEncontrado = getNodo(posicion);
    return nodoEncontrado->elemento;
}

//modifica el contacto en la posicion usando getnodo
void ListaEnlazada::setValor(int posicion, Contacto nuevoValor) {
    assertdomjudge(posicion >= 0 && posicion < n);
    assertdomjudge(n > 0);
    Nodo* nodoEncontrado = getNodo(posicion);
    nodoEncontrado->elemento = nuevoValor;
}

//devuelve la cantidad de elementos en la lista
int ListaEnlazada::getN() {
    return n;
}

//inserta un nuevo contacto en la posicion indicada
//si la posicion es 0 lo mete al principio, si es n al final
void ListaEnlazada::insertar(int posicion, Contacto nuevoValor) {
    assertdomjudge(posicion >= 0 && posicion <= n);
    Nodo* nuevoNodo = new Nodo{nuevoValor, nullptr};
    if (lista == nullptr) {
        nuevoNodo->siguienteNodo = nullptr;
        lista = nuevoNodo;
    } else if (posicion == 0) {
        nuevoNodo->siguienteNodo = lista;
        lista = nuevoNodo;
    } else {
        Nodo* nodoAnterior = getNodo(posicion - 1);
        nuevoNodo->siguienteNodo = nodoAnterior->siguienteNodo;
        nodoAnterior->siguienteNodo = nuevoNodo;
    }
    n++;
    //resetea los pteros porque cambia la estructura
    posicionUltimoNodoAccedido = -1;
    punteroUltimoNodoAccedido = nullptr;
}

//elimina el nodo en la posicion indicada
//si es el primero lo trata aparte, si no busca el anterior
void ListaEnlazada::eliminar(int posicion) {
    assertdomjudge(posicion >= 0 && posicion < n);
    assertdomjudge(n > 0);
    if (posicion == 0) {
        Nodo* nodoAEliminar = lista;
        lista = lista->siguienteNodo;
        delete nodoAEliminar;
    } else {
        Nodo* nodoAnterior = getNodo(posicion - 1);
        Nodo* nodoAEliminar = nodoAnterior->siguienteNodo;
        nodoAnterior->siguienteNodo = nodoAEliminar->siguienteNodo;
        delete nodoAEliminar;
    }
    n--;
    //borra la cache porque cambio la lista
    posicionUltimoNodoAccedido = -1;
    punteroUltimoNodoAccedido = nullptr;
}

//concatena otra lista al final de esta, conecta el ultimo nodo con el primero de la otra
void ListaEnlazada::concatenar(ListaEnlazada* listaAConcatenar) {
    assertdomjudge(listaAConcatenar != nullptr);
    if (listaAConcatenar->getN() == 0) return;
    if (n == 0) {
        lista = listaAConcatenar->lista;
    } else {
        Nodo* ultimo = lista;
        while (ultimo->siguienteNodo != nullptr) {
            ultimo = ultimo->siguienteNodo;
        }
        ultimo->siguienteNodo = listaAConcatenar->lista;
    }
    n += listaAConcatenar->getN();
    listaAConcatenar->lista = nullptr;
    listaAConcatenar->n = 0;

    //se modifico la lista asi que reestablece los ptrs
    posicionUltimoNodoAccedido = -1;
    punteroUltimoNodoAccedido = nullptr;
}

//busca un contacto por telefono y devuelve su posicion o -1 si no esta
int ListaEnlazada::buscar(Contacto elementoABuscar) {
    Nodo* actual = lista;
    for (int i = 0; i < n; ++i) {
        if (actual->elemento.telefono == elementoABuscar.telefono) {
            return i;
        }
        actual = actual->siguienteNodo;
    }
    return -1;
}
