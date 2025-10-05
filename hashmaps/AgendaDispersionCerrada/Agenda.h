#pragma once 
#include <string>
using namespace std; 
class Agenda{

    private:
        int capacidad; //capacidad de la tabla hash
        int n; //num actual de elementos de la tabla
        string *nombres; //nombres de los contactos
        long *telefonos; //telefonos de los contactos
        bool* vacias; //puntero a array de booleanos de capacidad elementos
        bool* borradas; // '' de posiciones borradas. Capacidad elementos.

    public:
        Agenda(int capacidad); //inicializa capacidad y reserva capacidad elemetnos para todos los arrays
        ~Agenda(); //destructor libera memoria dinamica para los arrays
        int obtenerPosicion(long telefono); //implementa hash que permite obtener la posicion del nº de tlfn.
        int buscarContacto(long telefono); //devuelve la posicion de un contacto, dispersion cerrada, empezar busqueda a partir de obtenerPosicion
        int buscarHueco(long telefono); //busca el hueco adecuado para meter un contacto. Empieza por obtenerposicion y e lineal hasta encontrar.
        bool isLlena(); //indica si ha alcanzado su maxima capacidad
        bool existeContacto(long telefono); //devuelve si existe un contacto con un telefono
        string getContacto(long telefono); //devuelve el nombre del contacto con un telefono
        void introducirContacto(long telefono, string nombre); //introduce un contacto en la agenda
        void eliminarContacto(long telefono); //elimina un contacto de la agenda
        void imprimir(); //imprime la agenda
};