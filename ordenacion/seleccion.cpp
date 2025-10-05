/*
Autor : Santiago Garcia Dominguez
Fecha : 10/02/2025. 
*/
#include<iostream>
using namespace std;

void ordenarSeleccion(int x[],int len)
{
  int menor = 0;
  int temporal = 0;

  for(int i=0;i<len;i++){
      /*Añadir código de ordenar mediante selección */
      menor = i;
      for(int j = i+1; j <len; j++){
        //Buscamos el menor en la lista
        if(x[j]<x[menor]){
          //posicion del menor
          menor = j;
        
        }
      }
      //guardamos en la v temporal el valor de la posicion i
      temporal = x[i];
      //intercambiamos valores
      x[i] = x[menor];
      x[menor] = temporal;

     
      for(int k=0;k<len;k++)
	    cout<<x[k]<<" ";
      cout<<endl;
    
  }  
}



int main()
{
 int n;
 cin>>n;
 int *x=new int[n];
 for(int i=0;i<n;i++)
   cin>>x[i];
 ordenarSeleccion(x,n);
}

