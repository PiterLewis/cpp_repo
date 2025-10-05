#include<iostream>
using namespace std;

void combinar(int a[], int len_a, int b[], int len_b, int c[])
{
  cout << "llamada a combinar \n ";
  while (len_a > 0 && len_b > 0)
  {
    //si el contenido de a es menor que el
    //de b, metemos en c el contenido de a
    //avanzamos el puntero de a y -1 longitud del conj ordenado.
    if (*a <= *b)
    {
      *c = *a;
      a++;
      len_a--;
    }
    //si el cont de a es mayor, metemos b(menor)
    //en c, incrementamos su puntero y disminuimos la long
    //del b
    else
    {
      *c = *b;
      b++;
      len_b--;
    }
    //después de agregar algo al c
    //incrementamos su puntero para no escribir
    //sobre datos que ya tenemos
    c++;
  }
  //si la long de a es mayor a 0.
  while (len_a > 0)
  {
    //contenido de c le metemos contenido de a
    //incrementamos ambos punteros y reducimos long de a
    *c = *a;
    a++;
    c++;
    len_a--;
  }
  //si la long de b es mayor a 0
  while (len_b > 0)
  {
    // lo mismo que antes + dec b
    *c = *b;
    b++;
    c++;
    len_b--;
  }
}



void ordenarMergeSort (int x[], int len)
{
  int temp[len];
  if(len == 1) /*caso básico */
    return;
  else
    {
      /*Ordenar dos mitades */
      int mitad = len / 2;
      ordenarMergeSort(x, mitad);
      cout << "acabe el primer ciclo de ordenar \n";
      //llamamos a ordenar la segunda mitad, x-> 0 + 5 y 10 -5 elementos
      ordenarMergeSort(x + mitad, len - mitad);
      /*Combinar ambas mitades y guardarlo en temp */
      cout << "acabe el segundo ciclo de ordenar \n";
      combinar(x, mitad, x + mitad, len - mitad, temp);
      /*Copiar del array temporal al array resultado */
      for (int k = 0; k < len; k++)
	{
	  x[k] = temp[k];
	  cout<<x[k]<<" ";
	}
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
 ordenarMergeSort(x,n);
}

