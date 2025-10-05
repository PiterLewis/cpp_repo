#ifndef MATRIZ_H
#define MATRIZ_H

using namespace std;

class Matriz {
private:
    double **matriz;
    int n_filas;
    int n_columnas;

public:
    /* 
      Constructor por defecto
      Crea una matriz vacía   

      Parámetros: Ninguno
      Retorno: Ninguno

    */
    Matriz();

    /* 
       Constructor parametrizado
       Crea una matriz con el número de filas y columnas especificado

       Parámetros:
       - n_filas: Número de filas de la matriz
       - n_columnas: Número de columnas de la matriz

       Retorno: Ninguno  

       Precondición:
       - n_filas y n_columnas deben ser mayores a 0  
       Complejidad Temporal: O(n_filas * n_columnas)  
       Complejidad Espacial: O(n_filas * n_columnas)  
    */
    Matriz(int n_filas, int n_columnas);

    /* 
       Constructor de copia
       Crea un nuevo objeto de tipo Matriz copiando los valores de otra matriz

       Parámetros:
       - m: Matriz a copiar

       Retorno: Ninguno  

       Precondición:
       - La matriz m debe estar correctamente inicializada y tener nfilasycolumnas > 0
       Complejidad Temporal: O(n_filas * n_columnas)  
       Complejidad Espacial: O(n_filas * n_columnas)  
    */
    Matriz(const Matriz &m);

    /* 
       Destructor de la clase Matriz 
       Libera la memoria asignada dinámicamente a la matriz

       Parámetros: Ninguno  
       Retorno: Ninguno  

       Precondición: Ninguna  
       Complejidad Temporal: O(n_filas)  
       Complejidad Espacial: O(1)  
    */
    ~Matriz();

    /* 
       Operador de suma (+)  
       Realiza la suma de dos matrices del mismo tamaño

       Parámetros:
       - m: Matriz con la que se sumará

       Retorno: Una nueva matriz con el resultado de la suma

       Precondición:
       - Ambas matrices deben tener las mismas dimensiones.  
       Complejidad Temporal: O(n_filas * n_columnas)  
       Complejidad Espacial: O(n_filas * n_columnas)  
    */
    Matriz operator+(const Matriz &m);

    /* 
       Operador de resta (-)
       Realiza la resta de dos matrices del mismo tamaño

       Parámetros:
       - m: Matriz que se restará

       Retorno: Una nueva matriz con el resultado de la resta

       Precondición:
       - Ambas matrices deben tener las mismas dimensiones  
       Complejidad Temporal: O(n_filas * n_columnas)  
       Complejidad Espacial: O(n_filas * n_columnas)  
    */
    Matriz operator-(const Matriz &m);

    /* 
       Operador de multiplicación (*)  
       Realiza la multiplicación de dos matrices

       Parámetros:
       - m: Matriz con la que se multiplicará

       Retorno: Una nueva matriz con el resultado de la multiplicación

       Precondición:
       - El número de columnas de la primera matriz debe ser igual al número de filas de la segunda
       Complejidad Temporal: O(n_filas * n_columnas * m.n_columnas)  
       Complejidad Espacial: O(n_filas * m.n_columnas)  
    */
    Matriz operator*(const Matriz &m);

    /* 
       Operador de multiplicación por escalar (*) 
       Multiplica cada elemento de la matriz por un número escalar

       Parámetros:
       - escalar: Valor por el que se multiplicará cada elemento

       Retorno: Una nueva matriz con el resultado de la multiplicación

       Precondición: Ninguna  
       Complejidad Temporal: O(n_filas * n_columnas)  
       Complejidad Espacial: O(n_filas * n_columnas)  
    */
    Matriz operator*(double escalar);

    /* 
       Operador de asignación (=)  
       Asigna los valores de una matriz a otra

       Parámetros:
       - m: Matriz que se asignará.

       Retorno: Referencia al objeto actual con los valores asignados

       Precondición: Ninguna  
       Complejidad Temporal: O(n_filas * n_columnas)  
       Complejidad Espacial: O(n_filas * n_columnas)  
    */
    Matriz& operator=(const Matriz &m);

    /* 
       Método para rellenar la matriz manualmente  
       Solicita al usuario los valores para cada celda de la matriz

       Parámetros: Ninguno  
       Retorno: Ninguno  

       Precondición:
       - La matriz debe estar correctamente inicializada  
       Complejidad Temporal: O(n_filas * n_columnas)  
       Complejidad Espacial: O(1)  
    */
    void rellenarManual();

    /* 
       Método para rellenar la matriz con valores aleatorios 
       Genera valores aleatorios para cada celda de la matriz

       Parámetros:
       - seed: Semilla para el generador de números aleatorios

       Retorno: Ninguno  

       Precondición:
       - La matriz debe estar correctamente inicializada
       Complejidad Temporal: O(n_filas * n_columnas)  
       Complejidad Espacial: O(1)  
    */
    void rellenarAleatorio(long seed);

    /* 
       Método para mostrar la matriz  
       Imprime en la consola todos los elementos de la matriz en formato de tabla

       Parámetros: Ninguno  
       Retorno: Ninguno  

       Precondición:
       - La matriz debe estar correctamente inicializada 
       Complejidad Temporal: O(n_filas * n_columnas)  
       Complejidad Espacial: O(1)  
    */
    void mostrarMatriz();

    /* 
       Método para calcular la traspuesta de la matriz 
       Intercambia las filas por las columnas

       Parámetros: Ninguno  
       Retorno: Una nueva matriz con la transposición

       Precondición:
       - La matriz debe estar correctamente inicializada  
       Complejidad Temporal: O(n_filas * n_columnas)  
       Complejidad Espacial: O(n_filas * n_columnas)  
    */
    Matriz calcularTraspuesta();

    /* 
       Método para verificar si la matriz es simétrica
       Comprueba si la matriz es igual a su traspuesta

       Parámetros:Ninguno
       Retorno: `true` si la matriz es simétrica, `false` en caso contrario

       Precondición:
       - La matriz debe ser cuadrada (n_filas == n_columnas).  
       Complejidad Temporal: O(n_filas * n_columnas)  
       Complejidad Espacial: O(1)  
    */
    bool esSimetrica();

    /* 
       Método para obtener el valor máximo de la matriz  
       Busca y devuelve el mayor valor presente en la matriz

       Parámetros: Ninguno  
       Retorno: El valor máximo en la matriz

       Precondición:
       - La matriz debe estar correctamente inicializada 
       Complejidad Temporal: O(n_filas * n_columnas)  
       Complejidad Espacial: O(1)  
    */
    double obtenerMaximo();

    /* 
       Método para obtener el valor mínimo de la matriz 
       Busca y devuelve el menor valor presente en la matriz

       Parámetros: Ninguno  
       Retorno: El valor mínimo en la matriz

       Precondición:
       - La matriz debe estar correctamente inicializada  
       Complejidad Temporal: O(n_filas * n_columnas)  
       Complejidad Espacial: O(1)  
    */
    double obtenerMinimo();

    double calcularDeterminante();

    
};

#endif // MATRIZ_H
