#include "Agenda.h"
#include "assertdomjudge.h"
#include <iostream>

using namespace std;

//constructor por parametros
Agenda::Agenda(int capacidad){
	assertdomjudge(capacidad >= 0); //control de errores, no permitimos capacidad negativa

	this->capacidad = capacidad;
	this->n = 0;
	this->nombres = new string[capacidad];
	this->telefonos = new long[capacidad];
	this->vacias = new bool[capacidad];
	this->borradas = new bool[capacidad];

	for(int i = 0; i<capacidad; i++){
		borradas[i] = false;
		vacias[i] = true;
	}
}

//destructor libera memoria dinámica
Agenda::~Agenda(){
	delete[] nombres;
	delete[] telefonos;
	delete[] vacias;
	delete[] borradas;
}

int Agenda::obtenerPosicion(long telefono){
	assertdomjudge(telefono >= 0); //control por si se mete un telefono negativo
	//permite obtener la posicion que corresponde al telefono, lo mismo q sincolision
	int pos = telefono % capacidad;
	return pos;
}

int Agenda::buscarHueco(long telefono){
	//buscamos el hueco adecuado para insertar el contacto
	int pos = obtenerPosicion(telefono);
	int contador = 0;

	//mientras que la posicion esté ocupada y no sea reutilizable, seguimos buscando
	while(contador < capacidad && !(vacias[pos] || borradas[pos])) { 
		pos = (pos + 1) % capacidad;
		contador++;
	}

	//si damos la vuelta entera y no hay hueco es que está llena
	assertdomjudge(contador < capacidad); //nos aseguramos de que haya hueco

	//devolvemos la posicion donde podemos insertar
	return pos;
}

int Agenda::buscarContacto(long telefono) {
    int posInicial = obtenerPosicion(telefono);
    int pos = posInicial;
    
    //primera iteración fuera del while
    if (vacias[pos] && !borradas[pos]) {
        return -1;
    }
    if (!vacias[pos] && telefonos[pos] == telefono) {
        return pos;
    }
	//actualizamos la posicion
    pos = (pos + 1) % capacidad;
    
    //resto de iteraciones
    while (pos != posInicial) {
        if (vacias[pos] && !borradas[pos]) {
            return -1;
        }
        if (!vacias[pos] && telefonos[pos] == telefono) {
            return pos;
        }
        pos = (pos + 1) % capacidad;
    }
    
    return -1;
}
bool Agenda::isLlena(){
	//indica si la tabla ha alcanzado su maxima capacidad
	if(this->n == this->capacidad){
		return true;
	}

	//si no se han alcanzado capacidad y n no devolvemos true.
	return false;
}

bool Agenda::existeContacto(long telefono){
	//llamamos a buscar contacto que haga la busqueda lineal y si nos devuelve -1 sabemos que no existe
	int pos = buscarContacto(telefono);
	if(pos != -1){
		return true;
	}

	return false; 
}

string Agenda::getContacto(long telefono){
	//si no existe el contacto, error
	assertdomjudge(existeContacto(telefono));
	int pos = buscarContacto(telefono);
	return nombres[pos]; //simplemente devolvemos el nombre
}

void Agenda::introducirContacto(long telefono, string contacto){
	//si el usuario ya esta en la tabla o la tabla esta llena
	assertdomjudge(!isLlena()); 
	int pos = buscarHueco(telefono); //con esto ya tenemos el hueco o error por capacidad
	assertdomjudge(pos != -1); //por si acaso

	telefonos[pos] = telefono; //asignamos el telefono a dicha posicion
	nombres[pos] = contacto; //asignamos el contacto
	vacias[pos] = false;
	borradas[pos] = false;
	this->n++; //sumamos uno a la cantidad de contactos
}

void Agenda::eliminarContacto(long telefono) {
    int pos = buscarContacto(telefono); //busca la posicion
    assertdomjudge(pos != -1); //comprobamos que no es numero negativo
    vacias[pos] = true; //ponemos vacia a true
    borradas[pos] = true; //y borrada tambien a true
    this->n--; //reducimos n
}

void Agenda::imprimir() {
	for (int i=0; i<capacidad; i++) 
		cout << "Posicion " << i << " | Vacia: " << vacias[i] << " | Borrada: " << borradas[i] << " | Telefono: " << telefonos[i] << " | Nombre: " << nombres[i] << endl;
}
