#include"Pila.h"
#include "assertdomjudge.h"
//constructor por parametros
Pila::Pila(string name)
{
  cima = NULL; //al principio no hay nodos
  this->name = name;
}

std::string Pila::nombrePila()
{
  return name;
}

void Pila::apilar(int num)
{
  //recibe un numero que representa el tamaño del disco y lo coloca en la cima de la piba
  Nodo* nuevoDisco = new Nodo(num); //creamos el disco con el valor
  //si la lista esta vacia, es el unico nodo y no tiene siguiente
  //pero si la lista no está vacía hay que conectar el anterior al nuevo nodo
  if(cima == NULL){
    cima = nuevoDisco;
    cout<<"Apilando disco "<<num<<" en poste "<<name<<endl;
    return;
  }

  //si ya habían discos hacemos que nuevoDisco apunte a cima y reubicamos el puntero de cima a nuevoDisco
  nuevoDisco->siguiente = cima;
  cima = nuevoDisco;

  cout<<"Apilando disco "<<num<<" en poste "<<name<<endl;
}
  
int Pila::desapilar()
{    
  assertdomjudge(cima != NULL); //si la cima es Nula no hay nodos que desapilar

  //si la cima no es Nula, debemos desapilar (desreferenciar el nodo de la cima)
  Nodo* refAcima = cima; //guardamos este puntero para acceder al nodo que se va a desapilar

  cima = cima->siguiente; //actualizamos el puntero de cima al siguiente nodo

  cout << "Desapilando disco " << refAcima->valor << " del poste " << name << endl;

  int valor = refAcima->valor; //guardamos el valor del nodo a desapilar

  delete refAcima; //liberamos la memoria del nodo eliminado

  //debemos devolver el valor del nodo a desapilar
  return valor;
}


bool Pila::estaVacia()
{
  if(cima == NULL){ //cuando el stack no contiene elementos
    return true; //esta vacia
  }else{
    return false;
  }
}

