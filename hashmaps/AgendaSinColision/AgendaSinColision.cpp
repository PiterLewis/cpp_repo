#include "Agenda.h"
#include "assertdomjudge.h"
#include <iostream>

using namespace std;

//constructor por parametros
Agenda::Agenda(int capacidad){
    //precondicion que capacidad sea mayor que 0
    assertdomjudge(capacidad > 0);
    
    this->capacidad = capacidad;

    //reservamos memoria para los arrays
    this->nombres = new string[capacidad];
    this->telefonos = new long[capacidad];
    this->ocupados = new bool[capacidad];

    //inicializamos ocupados como falso
    for(int i = 0; i < capacidad; i++){
        ocupados[i] = false;
    }
}

//destructor libera la memoria dinamica
Agenda::~Agenda(){
    delete[] nombres;
    delete[] telefonos;
    delete[] ocupados;
}

//devuelve la posicion de la tabla para un numero
int Agenda::obtenerPosicion(long telefono){
    //precondicion que el telefono no sea negativo
    assertdomjudge(telefono >= 0);
    return telefono % capacidad;
}

//devuelve si existe un contacto con ese numero
bool Agenda::existeContacto(long telefono){
    int pos = obtenerPosicion(telefono);
    return ocupados[pos] && telefonos[pos] == telefono;
}

//devuelve el nombre asociado al telefono si existe
string Agenda::getContacto(long telefono){
    int pos = obtenerPosicion(telefono);
    //nos aseguramos que existe
    assertdomjudge(existeContacto(telefono));
    return nombres[pos];
}

//introduce un nuevo contacto en la agenda
void Agenda::introducirContacto(long telefono, string contacto){
    int pos = obtenerPosicion(telefono);
    //solo si esta libre, no permitimos colision
    assertdomjudge(!ocupados[pos]);

    nombres[pos] = contacto;
    telefonos[pos] = telefono;
    ocupados[pos] = true;
}

//elimina un contacto si existe
void Agenda::eliminarContacto(long telefono){
    int pos = obtenerPosicion(telefono);
    //comprobamos que existe antes de borrar
    assertdomjudge(existeContacto(telefono));
    ocupados[pos] = false;
}
void Agenda::imprimir() {
	for (int i=0; i<capacidad; i++) cout << "Posicion " << i << " | Ocupada: " << ocupados[i] << " | Telefono: " << telefonos[i] << " | Nombre: " << nombres[i] << endl;
}