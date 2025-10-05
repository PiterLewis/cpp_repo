#pragma once
#include "ListaContigua.h"

// Clase que implementa una cola con prioridad mediante un monticulo (arbol binario completo en el cual la clave de cada nodo es menor que la de sus descendientes) e implementado sobre una lista contigua
class ColaPrioridad
{
protected:

	ListaContigua vector; 

public:

	void encolar(int nuevoElemento); //recibe un numero que representa el orden de llegada del cliente al supermercado.
	//escalar hasta la posicion que le corresponda dentro del montículo. Se intercambia con su padre hasta ser mayor que el o hasta raiz
	int desencolar();

	bool estaVacia();

protected:
	
	void reestructurar();
};

