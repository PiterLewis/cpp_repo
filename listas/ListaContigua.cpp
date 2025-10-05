/*
*   @author Santiago Garcia
*   @date 10/03/2025
*
*/

#include <iostream>
using namespace std;
#include "ListaContigua.h"
#include <cstring>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

// constructor
ListaContigua::ListaContigua(int incremento) {
    this->incremento = incremento;
    this->n = 0;
    this->capacidad = incremento;
    this->vector = (int*)malloc(capacidad * sizeof(int));
    assertdomjudge(vector != nullptr); // verificar que la memoria se asigno bien
}

// destructor
ListaContigua::~ListaContigua() {
    free(vector); // liberar memoria
}

// metodo getValor
int ListaContigua::getValor(int posicion) {
    // Precondición: La posición debe estar dentro de los límites válidos
    assertdomjudge(posicion >= 0 && posicion < n);
    //devuelve el valor en la posicion indicada
    return vector[posicion];
}

// metodo setValor
void ListaContigua::setValor(int posicion, int nuevoValor) {
    // Precondición: La posición debe estar dentro de los límites válidos
    assertdomjudge(posicion >= 0 && posicion < n);
    vector[posicion] = nuevoValor;
}

// metodo getN
int ListaContigua::getN() {
    return n;
}

// metodo getCapacidad
int ListaContigua::getCapacidad() {
    return capacidad;
}

// metodo insertar
void ListaContigua::insertar(int posicion, int nuevoValor) {
    //la posicion debe estar dentro de los límites validos
    assertdomjudge(posicion >= 0 && posicion <= n);

    //si la lista está llena, aumentar la capacidad
    if (n == capacidad) {
        capacidad += incremento;
        int* temp = (int*)realloc(vector, capacidad * sizeof(int));
        assertdomjudge(temp != nullptr); //la memoria se reasigna correctamente
        vector = temp;
    }

    // desplazar los elementos a la derecha para hacer espacio
    memmove(vector + posicion + 1, vector + posicion, (n - posicion) * sizeof(int));
    vector[posicion] = nuevoValor;
    n++;
}

// metodo eliminar
void ListaContigua::eliminar(int posicion) {
    // la posición debe estar dentro de los límites válidos
    assertdomjudge(posicion >= 0 && posicion < n);

    // desplazar los elementos a la izquierda para eliminar el elemento
    memmove(vector + posicion, vector + posicion + 1, (n - posicion - 1) * sizeof(int));
    n--;

    // reducir la capacidad si es necesario
    if (n <= capacidad - (2 * incremento) && capacidad > incremento) {
        capacidad -= incremento;
        int* temp = (int*)realloc(vector, capacidad * sizeof(int));
        if (temp != nullptr) {
            vector = temp;
        }
    }
}

// metodo concatenar
void ListaContigua::concatenar(ListaContigua *listaAConcatenar) {
    // la lista a concatenar no debe ser nullptr
    assertdomjudge(listaAConcatenar != nullptr);

    // si la capacidad actual no es suficiente, aumentarla
    if (n + listaAConcatenar->getN() > capacidad) {
        capacidad = n + listaAConcatenar->getN();
        int* temp = (int*)realloc(vector, capacidad * sizeof(int));
        vector = temp;
    }

    // copiar los elementos de la lista a concatenar
    for (int i = 0; i < listaAConcatenar->getN(); i++) {
        vector[n + i] = listaAConcatenar->getValor(i);
    }
    n += listaAConcatenar->getN();
}

// metodo buscar
int ListaContigua::buscar(int elementoABuscar) {
    // el elemento a buscar debe ser un valor válido
    assertdomjudge(elementoABuscar >= 0);

    //buscar el elemento en la lista
    for (int i = 0; i < n; i++) {
        if (vector[i] == elementoABuscar) {
            return i; // devolver la posición si se encuentra
        }
    }
    return -1; // -1 si no se encuentra
}