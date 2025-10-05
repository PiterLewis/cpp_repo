#include "Supermercado.h"
#include <iostream>
#include "assertdomjudge.h"
Supermercado::Supermercado(int n){
    this->n_cajas = n; //n cajas contienen el valor n
    this->cajas = new ColaPrioridad[n]; //n arrays de tipo ColaPrioridad
}

void Supermercado::nuevoUsuario(int n, int id){
    //encola el usuario con el id indicado en la caja que se encuentra en la posicion n
    //del array de cajas
    assertdomjudge(n >= 0 && n < n_cajas);
    this->cajas[n].encolar(id);
}

void Supermercado::cerrarCaja(int n){
    //simula el cierre de la caja y reparto
    //desencola todos los usuarios de una caja y los coloca en las vacías
    assertdomjudge(n >= 0 && n < n_cajas);
    int aux = 0;
    while(!cajas[n].estaVacia()){ // mientras que la caja que se quiere cerrar tenga elementos
        //repartimos a las demás
        for(int i = 0; i < n_cajas; i++){
            //if n es distinto de i para no encolar sobre la caja cerrada
            if(n != i && !cajas[n].estaVacia()){
                aux = cajas[n].desencolar(); //desencola un usuario de la caja cerrada
                cajas[i].encolar(aux);       //encola ese usuario en otra caja
            }
        }
    }
}

int Supermercado::atenderUsuario(int n){
    //atiende a un usuario de la caja n y por tanto lo desencola
    assertdomjudge(n >= 0 && n < n_cajas);
    int aux = cajas[n].desencolar();
    
    return aux; 
}

bool Supermercado::cajaVacia(int n){
    //indica si la caja tien o no usuarios esperando
    assertdomjudge(n >= 0 && n < n_cajas);
    if(cajas[n].estaVacia()){
        return true;
    }
    
    return false;
}