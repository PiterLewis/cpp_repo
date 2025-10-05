/*
Autor : Santiago García Domínguez
Curso : INSO 2º A
Fecha : 21 / 02 / 2025
*/
#include <iostream>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}
// #include <math.h>  usé pow() pero no me funcionó
using namespace std;

float raizRecursiva(float input, float error, float minimo, float maximo);
int main(){

    float input;
    cin >> input;
    assertdomjudge(input > 0);
    
    float error;
    cin >> error;
    assertdomjudge(error > 0);

    float vMedio = input / 2;
    float resF = raizRecursiva(input, error, 0, input);

}

float raizRecursiva(float input, float error, float min, float max) {
    //aproximamos entre los valores, en este caso 0 y el input
    float vMedio = (min + max) / 2;
    cout << vMedio << endl;

    //calculamos la diferencia entre el cuadrado de vMedio y el input
    //usé pow porque ya conocía la función de math (numero, potencia)
    float diferencia = vMedio * vMedio - input;
    //hacemos que la diferencia se halle en positivo porque si es negativa siempre va a
    //ser menor que el error.
    if(diferencia < 0){
        diferencia = -diferencia;
    }
    //si el valor absoluto de la diferencia es menor al error devolvemos el valorMedio
    if(diferencia < error){
        return vMedio;
    }
    //si la diferencia(potencia e input) es menor que el error, devolvemos el valor
    
    // Si la potencia es mayor que el input, realizamos de nuevo la funcion 
    // peeeeeeero usamos el valorMedio como MAXIMO esta vez, para hacer la aproximacion
    // con 0 y el vMedio a la mitad. (si en esta vuelta es 16, se conv en el maximo de la siguiente)
    if (vMedio*vMedio > input) {
        return raizRecursiva(input, error, min, vMedio); 
    } else {
        return raizRecursiva(input, error, vMedio, max); 
    }
}

// n y error.
// Explicación -> complejidad estimada -> Depende de la precisión -> nuestra complejidad depende de la precisión. Va a ser complejidad logarítmica
// problema -> dividir a la mitad -> div .. -> div -> logaritmico.