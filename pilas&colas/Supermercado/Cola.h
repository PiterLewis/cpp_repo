#include"Nodo.h"  
class Cola
{
 private:
  //puntero al primer nodo
  Nodo *principio;
  //puntero al ultimo nodo
  Nodo *final;
 public:
 //constructor sin parametros
  Cola();
 //metodo encolar -> recibe numero (orden de llegada) y lo coloca al final
  void encolar(int num);  
  //metodo desencolar -> devuelve el numero que representa el primer clinete en la cola
  int desencolar();
  //metodo estaVacia -> devuelve true si la cola esta vacia
  bool estaVacia();  
};

  
