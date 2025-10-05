#pragma once
#include <string>
using namespace std;

#include "ListaEnlazada.h"
#include "impresionListasEnlazadas.h"

class Agenda {

private:
	int capacidad; // capacidad de la tabla hash
	int n;
	ListaEnlazada* tabla; // array de listas enlazadas

public:
	// constructorq inicializa la tabla con el tamaño dado
	Agenda(int capacidad);

	// destructorq libera la memoria dinámica reservada
	~Agenda();

	// función hash obtiene la posición para un teléfono
	int obtenerPosicion(long telefono);

	// devuelve si existe un contacto con ese número
	bool existeContacto(long telefono);

	// devuelve el nombre asociado a un teléfono
	string getContacto(long telefono);

	// entroduce un nuevo contacto
	void introducirContacto(long telefono, string nombre);

	// elimina el contacto con ese número
	void eliminarContacto(long telefono);

	// Imprime el contenido completo de la agenda
	void imprimir();
};