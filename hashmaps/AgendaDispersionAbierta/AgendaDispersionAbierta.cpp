#include "Agenda.h"
#include "assertdomjudge.h"
#include "ListaEnlazada.h"
#include "impresionListasEnlazadas.h"
#include <iostream>
using namespace std;


//constructor por parámetros
Agenda::Agenda(int capacidad) {
    assertdomjudge(capacidad > 0);
    this->capacidad = capacidad;
    this->n = 0;
    tabla = new ListaEnlazada[capacidad]; //reservamos espacio para la tabla
}

//destructor libera memoria dinamica
Agenda::~Agenda() {
    delete[] tabla;
}

//funcion hash
int Agenda::obtenerPosicion(long telefono) {
    assertdomjudge(telefono >= 0);
    return (telefono % capacidad + capacidad) % capacidad; //forma reducida tambien podemos almacenar en variable y devolver como he estado haciendo
}

//comprueba si un contacto ya existe en la tabla
bool Agenda::existeContacto(long telefono) {
    int pos = obtenerPosicion(telefono);
    ListaEnlazada &lista = tabla[pos]; //en vez de crear copia usamos la ref

    for (int i = 0; i < lista.getN(); i++) {
        if (lista.getValor(i).telefono == telefono){
            return true;
		}
	}
    return false;
}

//obtiene el nombre del contacto a partir de su numero
string Agenda::getContacto(long telefono) {
    int pos = obtenerPosicion(telefono);
    ListaEnlazada &lista = tabla[pos]; //lo mismo

    for (int i = 0; i < lista.getN(); i++) {
        Contacto actual = lista.getValor(i);
        if (actual.telefono == telefono)
            return actual.nombre;
    }

    assertdomjudge(false); //si no lo encuentra, forzar un error lo cual no debería pasar nunca
    return ""; //por si acaso devolvemos cadena vacia
}

//introduce un nuevo contacto o actualiza si ya existe
void Agenda::introducirContacto(long telefono, string nombre) {
    int pos = obtenerPosicion(telefono);
    ListaEnlazada &lista = tabla[pos];

    Contacto nuevo;
    nuevo.telefono = telefono;
    nuevo.nombre = nombre;

    int i = lista.buscar(nuevo);
    if (i != -1) {
        lista.setValor(i, nuevo); //si ya existe, lo actualiza
    } else {
        lista.insertar(0, nuevo); //lo añade al principio
        n++;
    }
}

//elimina el contacto si existe
void Agenda::eliminarContacto(long telefono) {
    int pos = obtenerPosicion(telefono);
    ListaEnlazada &lista = tabla[pos];

    Contacto c;
    c.telefono = telefono;

    int i = lista.buscar(c);
    assertdomjudge(i != -1); //el contacto debe existir
    lista.eliminar(i);
    n--;
}

void Agenda::imprimir() {
    for (int i = 0; i < capacidad; i++) {
		cout << "Posicion " << i << ": ";
        imprimirListaEnlazada(&tabla[i]);
    }
}
