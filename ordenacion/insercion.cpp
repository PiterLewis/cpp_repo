/*
Autor : Santiago García Domínguez
Fecha : 10/02/2025.
*/
#include<iostream>
using namespace std;

void ordenarInsercion(int x[],int len)
{
  int temp;
  int j; 
  for(int i=1;i<len;i++)
    {
      // igualamos la variable temporal al primer elemento
      temp = x[i];
      // j se iguala a i-1 para comparar con el elemento anterior
      j = i-1;
      while(j>=0 && x[j]>temp){
        // si el elemento anterior es mayor que el actual, se intercambian
        x[j+1] = x[j];
        j = j-1;
      }
      // se guarda el valor temporal en la posicion j+1
      x[j+1] = temp;
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
 ordenarInsercion(x,n);
}


