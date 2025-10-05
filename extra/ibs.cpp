/*
*
*   Inserción + burbuja + selección All in 1
*
*
*/
#include <iostream>
using namespace std;

void ordenarBurbuja(int x[],int len)
{ 
  int temporal;
  for(int i=1;i<len;i++)
    { 
        
      /*Añadir código de ordenación usando algoritmo de burbuja*/
      for(int j = 0; j<len-i; j++){
        //dentro del segundo bucle comparamos j y su siguiente
        if(x[j]>x[j+1]){
            //si x de j es mayor al siguiente, se intercambian
            temporal = x[j+1];
            x[j+1] = x[j];
            x[j] = temporal;

        }
      }

      for(int k=0;k<len;k++)
	cout<<x[k]<<" ";
      cout<<endl;
    }  
}

void ordenarInsercion(int x[],int len)
{
  int temp;
  int j; 
  for(int i=1;i<len;i++)
    {   
        temp = x[i]; //igualamos la var temp al primer elemento
        j = i-1; //j se iguala a i-1 para comparar con el elemento anterior
        while(j >= 0 && x[j] > temp){
            //si el elemento anterior es mayor que el actual se desplaza
            x[j+1] = x[j]; //como
            j--;
        }
        //al salir del bucle, como "copiamos el dato", para desplazarlo
        //salimos del bucle con j decrementada, así que en j+1 deberíamos dejar nuestra variable temporal
        //que es la que hemos igualado al principio del bucle
        // ejemplo: 2, 5, 4
        // 2, 5, 5
        // ahora, como 2 no es mayor a 4, y al seleccionar 2 estamos diciendo que x[j],
        // j = 0, el siguiente (5), hay que cambiarlo con 4.
        x[j+1] = temp;

     /*Añadir codigo de ordenación por inserción*/
      for(int k=0;k<len;k++)
	    cout<<x[k]<<" ";
      cout<<endl;
    }  
}

void ordenarSeleccion(int x[],int len)
{
  int menor = 0;
  int temporal = 0;

  for(int i=0;i<len;i++){
      /*Añadir código de ordenar mediante selección */
      menor = i;
      for(int j = i; j<len; j++){
        if(x[menor] > x[j]){
            menor = j; //con esto almacenamos el indice del menor de cada vuelta
        }
      }
      //intercambiamos 
      temporal = x[i];
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

 ordenarInsercion(x,n);
}
