#include "ColaPrioridad.h"
#include <iostream>
#include "assertdomjudge.h"

void ColaPrioridad::encolar(int num) {
    //Insertamos al final del vector (última posición del montículo)
    vector.insertarAlFinal(num);

    //Obtenemos la posición actual del elemento (el final)
    int pos = vector.getN() - 1;

    //Mientras no estemos en la raíz y la clave del padre sea mayor que la del hijo actual
    while (pos > 0) {
        int padre = (pos - 1) / 2;

        //Si el padre ya es menor o igual, entonces ya está bien colocado
        if (vector.getValor(padre) <= vector.getValor(pos)) {
            break;
        }

        //Si no intercambiamos padre e hijo
        int tmp = vector.getValor(padre);
        vector.setValor(padre, vector.getValor(pos));
        vector.setValor(pos, tmp);

        // Subimos la posición del hijo (ahora estamos en la del padre)
        pos = padre;
    }
}

int ColaPrioridad::desencolar(){
    assertdomjudge(!estaVacia());
    //devuelve el numero que representa el orden de llegada del cliente 
    //que se encuentra en la primera posicion del monticulo. 
    
    //PASOS:
    //  1. El primer elemento será sustituido por el ultimo elemento
    //  2. El último elemento de la cola será eliminado.
    //  3. Se deberá reestructurar el montículo usando el método reestructurar

    //guardamos el valor de la raiz
    int valor = vector.getValor(0);

    //movemos el ultimo elemento a la raiz
    int ultimo = vector.getValor(vector.getN() - 1);
    //Seteamos el valor del ultimo al nodo raiz
    vector.setValor(0, ultimo);
    //eliminamos el duplicado del final
    vector.eliminarAlFinal();
    //reesturcturamos el monticulo (aun sin definir)
    reestructurar();
    //devolvemos el valor del anterior raiz
    return valor;
}


bool ColaPrioridad::estaVacia(){
    //indica si la cola esta vacia
    if(vector.getN() == 0){
        return true;
    }

    return false;
}

void ColaPrioridad::reestructurar() {
    int pos = 0; //1º cogemos la raiz
    int n = vector.getN();

    while (true) {
        int hijoIzq = 2 * pos + 1;
        int hijoDer = 2 * pos + 2;
        int menor = pos;

        // Si el hijo izquierdo existe y es menor que el actual
        if (hijoIzq < n && vector.getValor(hijoIzq) < vector.getValor(menor)) {
            menor = hijoIzq;
        }

        // Si el hijo derecho existe y es aún menor
        if (hijoDer < n && vector.getValor(hijoDer) < vector.getValor(menor)) {
            menor = hijoDer;
        }

        // Si ya está en su sitio, salimos
        if (menor == pos) {
            break;
        }

        // Intercambiamos con el hijo más pequeño
        int temp = vector.getValor(pos);
        vector.setValor(pos, vector.getValor(menor));
        vector.setValor(menor, temp);

        // Bajamos a la posición del hijo con el que hicimos el swap
        pos = menor;
    }
}