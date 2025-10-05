#include<iostream>
#include"Pila.h"
#include"assertdomjudge.h"
using namespace std;

void Hanoi(int n, Pila* origen, Pila* destino, Pila* auxiliar)
{
    if (n == 1) {
        //caso base: si solo queda un disco, lo pasamos directamente del origen al destino
        int disco = origen->desapilar();//desapilo del origen y lo paso al destino(desapilar devuelve el numdisco)
        destino->apilar(disco);//apilamos en el destino
    } else {
        //mover n-1 discos al auxiliar
        Hanoi(n-1, origen, auxiliar, destino);
        //mover disco grande al destino
        int disco = origen->desapilar();
        destino->apilar(disco);
        //mover n-1 del auxiliar al destino
        Hanoi(n-1, auxiliar, destino, origen);
    }
}



int main()
{  
  Pila *A=new Pila("A");
  Pila *B=new Pila("B");
  Pila *C=new Pila("C");

  int n;
  cin>>n;
  assertdomjudge(n>0);
  for(int i=n;i>0;i--)
    A->apilar(i);

  Hanoi(n,A,C,B);
  
  for(int i=0;i<n;i++)
    C->desapilar();

  return 0;
  
}

