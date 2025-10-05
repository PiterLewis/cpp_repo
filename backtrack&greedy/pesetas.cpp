/*
@author Santiago Garcia Dominguez
Fecha: 09/03/2025
*/
#include <iostream>
using namespace std;
int main(){

    int entrada = 0;
    int monedas[] = {500, 200, 100, 50, 25, 10, 5, 1};
    int soluciones[8];

    
    //el programa corre en un bucle infinito hasta q ponemos un negativo
    while(entrada >= 0){
        //seguimos pidiendo pProducto o entrada
        cin >> entrada;
        if(entrada < 0){
            break; //no me gusta usar break en los while pero no vi otra solucion
        }
        //setear las soluciones a 0 despues de cada iteracion
        for(int i = 0; i<8; i++){
            soluciones[i] = 0;
        }

        for(int i= 0; i < 8; i++){
            //dividimos el cambio entre 500, si ponemos 1.000
            //se almacena 2 en soluciones(0)
            if(entrada >= monedas[i]){
                soluciones[i] = entrada / monedas[i];
                //el resto(lo que sobra de la division)
                //queda almacenado en cambio, pues todavia
                //falta eso por devolver
               entrada %= monedas[i]; 
            }
        }

        for(int j= 0; j < 8; j++){
            cout << soluciones[j] << " "; //imprimimos con espacio
        }
        cout << "\n";
        
    }


    return 0;
}