#include "ABB.h"
#include "assertdomjudge.h"
#include <iostream>
using namespace std;

/*
-complejidad:
  -temporal: O(h) en la mayoría, algunas funciones son O(1)
  -espacial: usualmente O(1), pero en recursión puede ser O(h) u O(n)
*/

// constructor, el árbol empieza vacío
ABB::ABB() {
    raiz = NULL;
    n = 0;
}

// destructor, borra todo lo que quede vivo en el árbol
ABB::~ABB() {
    eliminarSubarbol(raiz);
}

// inserta un nuevo elemento en el árbol
void ABB::insertar(int nuevoElemento) {
    Nodo* nuevoNodo = new Nodo(); // creamos nodo nuevo
    nuevoNodo->contenido = nuevoElemento; // le ponemos el valor

    if (n == 0) { // si no hay nodos aún
        raiz = nuevoNodo; // este será la raíz
    } else {
        // buscamos donde enganchar este nodo
        Nodo* posicion = buscarHueco(raiz, nuevoElemento);
        nuevoNodo->padre = posicion; // lo conectamos con su padre

        if (nuevoElemento < posicion->contenido) {
            posicion->hijoIzquierdo = nuevoNodo; // si es menor, va a la izquierda
        } else {
            posicion->hijoDerecho = nuevoNodo; // si no, a la derecha
        }
    }

    n++; // aumentamos el número de nodos
}

// busca un lugar libre para insertar un nodo nuevo
Nodo* ABB::buscarHueco(Nodo* raizSubarbol, int elementoAInsertar) {
    if (elementoAInsertar < raizSubarbol->contenido && raizSubarbol->hijoIzquierdo != NULL) {
        return buscarHueco(raizSubarbol->hijoIzquierdo, elementoAInsertar); // seguimos por la izquierda
    }
    if (elementoAInsertar > raizSubarbol->contenido && raizSubarbol->hijoDerecho != NULL) {
        return buscarHueco(raizSubarbol->hijoDerecho, elementoAInsertar); // seguimos por la derecha
    }

    return raizSubarbol; // cuando no podemos bajar más, este es el hueco
}

// busca un valor en el árbol
Nodo* ABB::buscar(int elementoABuscar) {
    if (raiz == NULL) {
        return NULL; // si el árbol está vacío, nada que buscar
    } else {
        return buscarRecursivo(raiz, elementoABuscar); // empezamos desde la raíz
    }
}

// versión recursiva de buscar
Nodo* ABB::buscarRecursivo(Nodo* raizSubarbol, int elementoABuscar) {
    if (raizSubarbol->contenido == elementoABuscar) {
        return raizSubarbol; // lo encontramos
    }

    if (elementoABuscar < raizSubarbol->contenido && raizSubarbol->hijoIzquierdo != NULL) {
        return buscarRecursivo(raizSubarbol->hijoIzquierdo, elementoABuscar); // buscamos a la izquierda
    }

    if (elementoABuscar > raizSubarbol->contenido && raizSubarbol->hijoDerecho != NULL) {
        return buscarRecursivo(raizSubarbol->hijoDerecho, elementoABuscar); // buscamos a la derecha
    }

    return NULL; // no está en el árbol
}

// elimina un nodo que ya conocemos (lo pasamos por puntero)
void ABB::eliminarNodo(Nodo* nodoParaEliminar) {
    Nodo* auxiliar;

    if (nodoParaEliminar->hijoDerecho != NULL && nodoParaEliminar->hijoIzquierdo != NULL) {
        // caso con dos hijos
        if (alturaNodo(nodoParaEliminar->hijoDerecho) > alturaNodo(nodoParaEliminar->hijoIzquierdo)) {
            auxiliar = buscarMinimo(nodoParaEliminar->hijoDerecho); // cogemos el menor del subárbol derecho
        } else {
            auxiliar = buscarMaximo(nodoParaEliminar->hijoIzquierdo); // o el mayor del izquierdo
        }
        nodoParaEliminar->contenido = auxiliar->contenido; // copiamos el contenido
        eliminarNodo(auxiliar); // y ahora eliminamos el duplicado
    } else if (nodoParaEliminar->hijoDerecho != NULL) {
        // tiene solo hijo derecho
        auxiliar = buscarMinimo(nodoParaEliminar->hijoDerecho);
        nodoParaEliminar->contenido = auxiliar->contenido;
        eliminarNodo(auxiliar);
    } else if (nodoParaEliminar->hijoIzquierdo != NULL) {
        // tiene solo hijo izquierdo
        auxiliar = buscarMaximo(nodoParaEliminar->hijoIzquierdo);
        nodoParaEliminar->contenido = auxiliar->contenido;
        eliminarNodo(auxiliar);
    } else {
        // es hoja
        if (nodoParaEliminar->padre != NULL) {
            if (nodoParaEliminar->padre->hijoDerecho == nodoParaEliminar) {
                nodoParaEliminar->padre->hijoDerecho = NULL;
            } else {
                nodoParaEliminar->padre->hijoIzquierdo = NULL;
            }
            delete nodoParaEliminar; // eliminamos la hoja
        } else {
            raiz = NULL; // era el único nodo, ahora está vacío
        }
    }
}

// busca un valor y lo elimina si lo encuentra
void ABB::eliminar(int elementoAEliminar) {
    Nodo* objetivo = buscar(elementoAEliminar);
    if (objetivo != NULL) {
        eliminarNodo(objetivo); // lo pasamos al eliminador
    }
}

// calcula la altura de un subárbol desde un nodo
int ABB::alturaNodo(Nodo* raizSubarbol) {
    if (raizSubarbol == NULL) {
        return 0; // altura de árbol vacío
    }

    int alturaIzq = alturaNodo(raizSubarbol->hijoIzquierdo); // calculamos la altura izquierda
    int alturaDer = alturaNodo(raizSubarbol->hijoDerecho); // y la derecha

    return max(alturaIzq, alturaDer) + 1; // sumamos 1 por el nodo actual
}

// busca el valor máximo (el de más a la derecha)
Nodo* ABB::buscarMaximo(Nodo* raizSubarbol) {
    if (raizSubarbol->hijoDerecho != NULL) {
        return buscarMaximo(raizSubarbol->hijoDerecho); // seguimos bajando
    }
    return raizSubarbol;
}

// busca el valor mínimo (el más a la izquierda)
Nodo* ABB::buscarMinimo(Nodo* raizSubarbol) {
    if (raizSubarbol->hijoIzquierdo != NULL) {
        return buscarMinimo(raizSubarbol->hijoIzquierdo);
    }
    return raizSubarbol;
}

// comprueba si cumple propiedad de ABB
bool ABB::esABB() {
    if (raiz == NULL) {
        return true; // árbol vacío es ABB válido
    }

    if (raiz->hijoDerecho != NULL) {
        if (buscarMinimo(raiz->hijoDerecho)->contenido < raiz->contenido || !esSubABB(raiz->hijoDerecho)) {
            return false;
        }
    }

    if (raiz->hijoIzquierdo != NULL) {
        if (buscarMaximo(raiz->hijoIzquierdo)->contenido > raiz->contenido || !esSubABB(raiz->hijoIzquierdo)) {
            return false;
        }
    }

    return true;
}

// misma validación pero para cualquier subárbol
bool ABB::esSubABB(Nodo* raizSubarbol) {
    if (raizSubarbol == NULL) {
        return true;
    }

    if (raizSubarbol->hijoDerecho != NULL) {
        if (buscarMinimo(raizSubarbol->hijoDerecho)->contenido < raizSubarbol->contenido || !esSubABB(raizSubarbol->hijoDerecho)) {
            return false;
        }
    }

    if (raizSubarbol->hijoIzquierdo != NULL) {
        if (buscarMaximo(raizSubarbol->hijoIzquierdo)->contenido > raizSubarbol->contenido || !esSubABB(raizSubarbol->hijoIzquierdo)) {
            return false;
        }
    }

    return true;
}

// comprueba si el árbol es AVL (balanceado)
bool ABB::esAVL() {
    if (!esABB()) {
        return false;
    }

    int balance = abs(alturaNodo(raiz->hijoIzquierdo) - alturaNodo(raiz->hijoDerecho)); // diferencia de alturas

    if (balance > 1) {
        return false;
    }

    if (raiz->hijoDerecho != NULL) {
        if (raiz->hijoDerecho->contenido < raiz->contenido || !esSubAVL(raiz->hijoDerecho)) {
            return false;
        }
    }

    if (raiz->hijoIzquierdo != NULL) {
        if (raiz->hijoIzquierdo->contenido > raiz->contenido || !esSubAVL(raiz->hijoIzquierdo)) {
            return false;
        }
    }

    return true;
}

// versión recursiva de la comprobación AVL
bool ABB::esSubAVL(Nodo* raizSubarbol) {
    int diferencia = abs(alturaNodo(raizSubarbol->hijoIzquierdo) - alturaNodo(raizSubarbol->hijoDerecho));

    if (diferencia > 1) {
        return false;
    }

    if (raizSubarbol->hijoDerecho != NULL) {
        if (raizSubarbol->hijoDerecho->contenido < raizSubarbol->contenido || !esSubAVL(raizSubarbol->hijoDerecho)) {
            return false;
        }
    }

    if (raizSubarbol->hijoIzquierdo != NULL) {
        if (raizSubarbol->hijoIzquierdo->contenido > raizSubarbol->contenido || !esSubAVL(raizSubarbol->hijoIzquierdo)) {
            return false;
        }
    }

    return true;
}

// borra todos los nodos colgando desde este
void ABB::eliminarSubarbol(Nodo* raizSubarbol) {
    if (raizSubarbol == NULL) {
        return;
    }

    if (raizSubarbol->hijoIzquierdo != NULL) {
        eliminarSubarbol(raizSubarbol->hijoIzquierdo);
        raizSubarbol->hijoIzquierdo = NULL;
    }

    if (raizSubarbol->hijoDerecho != NULL) {
        eliminarSubarbol(raizSubarbol->hijoDerecho);
        raizSubarbol->hijoDerecho = NULL;
    }

    delete raizSubarbol;
}

void ABB::imprimir()
{
  if(raiz==NULL)
    cout<<"VACIO"<<endl;
  else   
      imprimirRecorrido(raiz);    
}

void ABB::imprimirRecorrido(Nodo *raizSubarbol)
{
  cout<<raizSubarbol->contenido<<endl;
  if(raizSubarbol->hijoIzquierdo!=NULL)
    {
      cout<<"I";
      imprimirRecorrido(raizSubarbol->hijoIzquierdo);
      cout<<endl;
    }
  if(raizSubarbol->hijoDerecho!=NULL)
    {
      cout<<"D";
      imprimirRecorrido(raizSubarbol->hijoDerecho);
      cout<<endl;
    }
}

void ABB::leerArbol()
{
  raiz=leerSubarbol(NULL);
}

Nodo * ABB::leerSubarbol(Nodo *padre)
{
  int contenido;
  cin>>contenido;
  if(contenido>=0)
    {
      Nodo *arbol=new Nodo;
      arbol->contenido=contenido;
      arbol->hijoIzquierdo=leerSubarbol(arbol);
      arbol->hijoDerecho=leerSubarbol(arbol);
      arbol->padre=padre;
      return arbol;
    }
  else
    {
      return NULL;
    }
}


