/*
*   Triangulo
*   @details: Dado un triangulo en una matriz, devolver el camino
*   de arriba a bajo más corto.
*
*   @author : Santiago Garcia Dominguez
*   @date   : 25/09/2025
*
*/

#include <iostream>
#include <vector>

using namespace std;

int minimumTotal(vector<vector<int>> triangle);
int resolveArray(vector<int> vector);
int main(){  
    vector<vector<int>> triangle = 
    {{2},
     {3,4},
     {6,5,7},
     {4,1,8,3}
    };

    cout << "Solucion : " << minimumTotal(triangle) << endl;
    return 0;
}

int minimumTotal(vector<vector<int>> triangle) {

    //empty metodo de vector
    if (triangle.empty()) return 0;
    //back metodo de v, coge la ultima fila y la guarda en aux
    vector<int> aux = triangle.back();                 

    //doble for, -2 del tamaño para empezar encima de la fila
    //que acabamos de guardar
    for (int i = (int)triangle.size() - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {   
            //igualamos aux a la suma de
            //elemento de arriba + sub hijos (minimo de ellos)             
            aux[j] = triangle[i][j] + min(aux[j], aux[j+1]);
        }
    }
    //haciendo esto, queda la sol + óptima en el primer elemento,
    //porque coincide con la raiz
    return aux[0];
}
