#include "Matriz.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

// constructor por defecto
Matriz::Matriz() {
    n_filas = 0;
    n_columnas = 0;
    matriz = nullptr; // inicializa la matriz como un puntero nulo
}

// constructor por parametros
Matriz::Matriz(int filas, int columnas) {
    assertdomjudge(filas > 0 && columnas > 0); // verifica que las dimensiones sean validas
    n_filas = filas;
    n_columnas = columnas;
    matriz = new double*[filas]; // reserva memoria para las filas
    for (int i = 0; i < filas; i++) {
        matriz[i] = new double[columnas]; // reserva memoria para las columnas en cada fila
    }
}

// constructor de copia
Matriz::Matriz(const Matriz &m) {
    assertdomjudge(m.matriz != nullptr && m.n_filas > 0 && m.n_columnas > 0); // verifica que la matriz a copiar sea valida
    n_filas = m.n_filas;
    n_columnas = m.n_columnas;
    matriz = new double*[n_filas]; // reserva memoria para las filas
    for (int i = 0; i < n_filas; i++) {
        matriz[i] = new double[n_columnas]; // reserva memoria para las columnas en cada fila
        for (int j = 0; j < n_columnas; j++) {
            matriz[i][j] = m.matriz[i][j]; // copia los elementos de la matriz original
        }
    }
}

// destructor
Matriz::~Matriz() {
    if (matriz != nullptr) {
        for (int i = 0; i < n_filas; i++) {
            delete[] matriz[i]; // libera la memoria de cada fila
        }
        delete[] matriz; // libera la memoria de las filas
    }
}

// sobrecarga operador +
Matriz Matriz::operator+(const Matriz &m){
    assertdomjudge(n_filas == m.n_filas && n_columnas == m.n_columnas); // verifica que las dimensiones sean compatibles
    Matriz resultado(n_filas, n_columnas);
    for (int i = 0; i < n_filas; i++) {
        for (int j = 0; j < n_columnas; j++) {
            resultado.matriz[i][j] = matriz[i][j] + m.matriz[i][j]; // suma los elementos correspondientes
        }
    }
    return resultado;
}

// sobrecarga operador -
Matriz Matriz::operator-(const Matriz &m){
    assertdomjudge(n_filas == m.n_filas && n_columnas == m.n_columnas); // verifica que las dimensiones sean compatibles
    Matriz resultado(n_filas, n_columnas);
    for (int i = 0; i < n_filas; i++) {
        for (int j = 0; j < n_columnas; j++) {
            resultado.matriz[i][j] = matriz[i][j] - m.matriz[i][j]; // resta los elementos correspondientes
        }
    }
    return resultado;
}

// sobrecarga operador *
Matriz Matriz::operator*(const Matriz &m){
    assertdomjudge(n_columnas == m.n_filas); // verifica que las dimensiones sean compatibles para la multiplicacion
    Matriz resultado(n_filas, m.n_columnas);
    for (int i = 0; i < n_filas; i++) {
        for (int j = 0; j < m.n_columnas; j++) {
            resultado.matriz[i][j] = 0; // inicializa el elemento a 0
            for (int k = 0; k < n_columnas; k++) {
                resultado.matriz[i][j] += matriz[i][k] * m.matriz[k][j]; // realiza la multiplicacion de matrices
            }
        }
    }
    return resultado;
}

// sobrecarga operador * (escalar)
Matriz Matriz::operator*(double escalar){
    Matriz resultado(n_filas, n_columnas);
    for (int i = 0; i < n_filas; i++) {
        for (int j = 0; j < n_columnas; j++) {
            resultado.matriz[i][j] = matriz[i][j] * escalar; // multiplica cada elemento por el escalar
        }
    }
    return resultado;
}

// operador de asignacion
Matriz& Matriz::operator=(const Matriz &m) {
    if (this == &m) return *this; // auto-asignacion

    // liberar memoria previa
    if (matriz != nullptr) {
        for (int i = 0; i < n_filas; i++) {
            delete[] matriz[i]; // libera la memoria de cada fila
        }
        delete[] matriz; // libera la memoria de las filas
    }

    // copiar dimensiones y reservar memoria
    n_filas = m.n_filas;
    n_columnas = m.n_columnas;
    matriz = new double*[n_filas]; // reserva memoria para las filas
    for (int i = 0; i < n_filas; i++) {
        matriz[i] = new double[n_columnas]; // reserva memoria para las columnas en cada fila
        for (int j = 0; j < n_columnas; j++) {
            matriz[i][j] = m.matriz[i][j]; // copia los elementos de la matriz original
        }
    }
    return *this;
}

// rellenar matriz manualmente
void Matriz::rellenarManual() {
    assertdomjudge(matriz != nullptr && n_filas > 0 && n_columnas > 0); // verifica que la matriz sea valida
    double elemento;
    for (int i = 0; i < n_filas; i++) {
        std::cout << "Fila " << i << std::endl;
        for (int j = 0; j < n_columnas; j++) {
            std::cout << "Elemento " << j << std::endl;
            std::cin >> elemento; // lee el elemento desde la entrada estandar
            matriz[i][j] = elemento; // asigna el elemento a la matriz
        }
    }
}

// rellenar matriz aleatoriamente
void Matriz::rellenarAleatorio(long seed) {
    srand(seed); // inicializa la semilla para la generacion de numeros aleatorios
    for (int i = 0; i < n_filas; i++) {
        for (int j = 0; j < n_columnas; j++) {
            matriz[i][j] = rand(); // asigna un numero aleatorio a cada elemento de la matriz
        }
    }
}

// mostrar matriz
void Matriz::mostrarMatriz() {
    for (int i = 0; i < n_filas; i++) {
        for (int j = 0; j < n_columnas; j++) {
            std::cout << matriz[i][j] << " "; // imprime cada elemento de la matriz
        }
        std::cout << std::endl; // nueva linea al final de cada fila
    }
}

// calcular traspuesta
Matriz Matriz::calcularTraspuesta(){
    Matriz traspuesta(n_columnas, n_filas); // crea una nueva matriz con dimensiones invertidas
    for (int i = 0; i < n_filas; i++) {
        for (int j = 0; j < n_columnas; j++) {
            traspuesta.matriz[j][i] = matriz[i][j]; // asigna los elementos transpuestos
        }
    }
    return traspuesta;
}

// verificar si la matriz es simetrica
bool Matriz::esSimetrica(){
    assertdomjudge(n_filas == n_columnas); // verifica que la matriz sea cuadrada
    for (int i = 0; i < n_filas; i++) {
        for (int j = 0; j < i; j++) {
            if (matriz[i][j] != matriz[j][i]) { // verifica la simetria
                return false;
            }
        }
    }
    return true;
}

// obtener valor maximo
double Matriz::obtenerMaximo(){
    assertdomjudge(n_filas > 0 && n_columnas > 0 && matriz != nullptr); // verifica que la matriz sea valida
    double maximo = matriz[0][0]; // inicializa el maximo con el primer elemento
    for (int i = 0; i < n_filas; i++) {
        for (int j = 0; j < n_columnas; j++) {
            if (matriz[i][j] > maximo) {
                maximo = matriz[i][j]; // actualiza el maximo si se encuentra un elemento mayor
            }
        }
    }
    return maximo;
}

// obtener valor minimo
double Matriz::obtenerMinimo(){
    assertdomjudge(n_filas > 0 && n_columnas > 0 && matriz != nullptr); // verifica que la matriz sea valida
    double minimo = matriz[0][0]; // inicializa el minimo con el primer elemento
    for (int i = 0; i < n_filas; i++) {
        for (int j = 0; j < n_columnas; j++) {
            if (matriz[i][j] < minimo) {
                minimo = matriz[i][j]; // actualiza el minimo si se encuentra un elemento menor
            }
        }
    }
    return minimo;
}

double Matriz::calcularDeterminante() {
    /* Cálculo recursivo de un determinante por adjuntos */
    assertdomjudge(n_columnas>0 && n_filas>0); // para no hacerlo de una matriz neg
    // Si tenemos una matriz1x1
    // devolvemos su unico elemento
    if (n_filas == 1) {
        return matriz[0][0];
    }

    // Si tenemos una matriz2x2
    // sabemos que su det es axd y bxc
    if (n_filas == 2) {
        return matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
    }

    int res = 0;


    for (int i = 0; i < n_columnas; i++) {
        // creamos una submatriz de n-1 filas y n-1 columnas
        Matriz chiquita(n_filas - 1, n_columnas - 1);
        for (int j = 1; j < n_filas; j++) { // Empezamos desde la segunda fila
            int columnaSubmatriz = 0;
            for (int k = 0; k < n_columnas; k++) {
                if (k != i) { // K no puede coincidir con i
                    // porque cuando hacemos el det por adjuntos
                    // debemos "tachar" o eliminar la columna y fila i
                    chiquita.matriz[j - 1][columnaSubmatriz] = matriz[j][k];
                    columnaSubmatriz++;
                }
            }
        }

        // utilicé el ternario para sacar signo (+) o (-)
        int signo = (i % 2 == 0) ? 1 : -1;
        int producto = signo * matriz[0][i] * chiquita.calcularDeterminante();
        // multipliqué el +1/-1 por el primer elemento y luego por su submatriz
        // sumé los resultados al acumulador, que será devuelto como determinante
        res += producto;
    }

    return res;
}

// complejidad n!