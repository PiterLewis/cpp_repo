/*
Autor : Santiago Garcia Domniguez
Fecha : 10/02/2025.
*/
#include<iostream>
using namespace std;

void ordenarBurbuja(int x[],int len)
{ 
  int temporal;
  for(int i=1;i<len;i++)
    { 
      /*Añadir código de ordenación usando algoritmo de burbuja*/
      // recorremos pero vamos disminuyendo el tamaño, ya que el mayor elemento ya está en su lugar
      for(int j=0; j<len-i; j++){
        // si el elemento es mayor que el siguiente
        if(x[j]>x[j+1]){
          //intercambiamos valores
          temporal = x[j];
          x[j] = x[j+1];
          x[j+1] = temporal;

        }


      }

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
 ordenarBurbuja(x,n);
}
