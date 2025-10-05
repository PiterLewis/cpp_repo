#pragma once 
#include <string>
using namespace std; 
class Agenda{

    private:
        int capacidad; //capacidad de la tabla hash
        string *nombres; //nombres de los contactos
        long *telefonos; //telefonos de los contactos
        bool *ocupados; //1 ocupada, 0 vacia, tiene capacidad elementos

    public:
        Agenda(int capacidad); //inicializa capacidad y reserva capacidad elemetnos para todos los arrays
        ~Agenda(); //destructor libera memoria dinamica para los arrays
        int obtenerPosicion(long telefono); //implementa hash que permite obtener la posicion del nº de tlfn.
        bool existeContacto(long telefono); //devuelve si existe un contacto con un telefono
        string getContacto(long telefono); //devuelve el nombre del contacto con un telefono
        void introducirContacto(long telefono, string nombre); //introduce un contacto en la agenda
        void eliminarContacto(long telefono); //elimina un contacto de la agenda
        void imprimir(); //imprime la agenda
};