#include <iostream>
#include "Supermercado.h"
using namespace std;

// constructor con parámetro -> n cajas
Supermercado::Supermercado(int n){
    this->n_cajas = n;
    cajas = new Cola[n]; // reserva de memoria para las cajas
    /*cajas = (Cola*)malloc(n*sizeof(Cola)); -> esta forma no es válida en C++ */
}

void Supermercado::nuevoUsuario(int n, int id){
    // encola al usuario con el id en LA CAJA en la posición n del array de cajas
    if(n < 0 || n >= n_cajas){
        cout << "No válido" << endl;
        return; // salimos sin hacer nada
    }
    cajas[n].encolar(id);
}

void Supermercado::cerrarCaja(int n){
    // simula el cierre de la caja n
    // desencolamos los usuarios de esa caja y los repartimos entre las otras

    if(n < 0 || n >= n_cajas || n_cajas <= 1){
        cout << "No válido" << endl;
        return; // volvemos atrás
    }

    // mientras que haya nodos en la caja n
    while(!cajas[n].estaVacia()){
        // recorremos todas las cajas
        for(int i = 0; i < n_cajas; i++){
            // si la caja NO es la que estamos cerrando y aún quedan usuarios por repartir
            if(i != n && !cajas[n].estaVacia()){
                // desencolamos un cliente de la caja cerrada
                int cliente = cajas[n].desencolar();
                // lo encolamos en la siguiente caja activa
                cajas[i].encolar(cliente);
            }
        }
    }
}

int Supermercado::atenderUsuario(int n){
    // atiende al usuario que se encuentra en la caja n y por tanto 
    // lo desencola de la cola, devuelve el id del usuario atendido
    /* int valor = cajas[n].principio->valor; // si principio no fuera privado */

    if(cajaVacia(n)){
        cout << "La caja está vacía" << endl;
        return -1; // valor especial indicando que no se atendió a nadie
    }

    int valor = cajas[n].desencolar();
    return valor;
}

bool Supermercado::cajaVacia(int n){
    // indica si la caja n tiene o no tiene usuarios esperando
    if(cajas[n].estaVacia()){
        return true;
    }
    return false;
}
