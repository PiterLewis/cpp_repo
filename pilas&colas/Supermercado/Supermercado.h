#include"Cola.h"

class Supermercado
{
private:
  //array de punteros a objetos de tipo Cola
  Cola *cajas;
  //numero de cajas
  int n_cajas;
public:
  //contructor por parametro
  Supermercado(int n);
  //metodo nuevoUsuario -> encola al usuario con el id indicado en la caja que se encuentra en la posicion n del array
  void nuevoUsuario(int n,int id);  
  //metodo cerrarCaja -> simula el cierre de la caja n y el reparto a las demas cajas. 
  //1º Desencolamos a los usuarios en la caja n. 
  //2º Encolamos a los usuarios en las demas cajas de forma equitativa, introducimso un unico usuario por cada caja que no este vacía
  void cerrarCaja(int n);
  //metodo atenderUsuario-> atiende al usuario que se encuentra en la caja n y 
  //lo desencola de la cola que representa dicha caja. Devolvemos el id del usuario atnedido.
  int atenderUsuario(int n);
  //metodo cajaVacia -> indica si la caja n tiene o no tiene usuarios esperando.
  bool cajaVacia(int n);
};
