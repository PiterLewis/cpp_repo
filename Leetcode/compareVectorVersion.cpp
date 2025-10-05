/*
    Comparar dos 'versiones', una version es una cifra separada por puntos.
    El valor de una cifra es el integer de la cadena a convertir,
    ignorando ceros a la izquierda.

    @author : Santiago García Domínguez
    @date   : 23/09/2025

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int compareVersion(string v1, string v2);

int main(){

    string firstSample = "1.0.0.0.0.02";
    string secondSample = "1.0.0.0.4.0";

    int sol = compareVersion(firstSample, secondSample);
    cout << "Sol : " << sol << endl;

    return 0;
}

int compareVersion(string v1, string v2){

    
    vector<int> indicesPuntos(v1.length() + 1, 0);
    vector<int> valores(v1.length() + 1, 0);

    int contador = 0;
    for (int i = 0; i < (int)v1.length(); i++) {
        if (v1[i] == '.') {
            indicesPuntos[contador] = i;
            contador++;
        }
    }
    indicesPuntos[contador] = (int)v1.length();

    int prev = -1;
    for (int j = 0; j <= contador; j++) {
        int start = prev + 1;
        int end   = indicesPuntos[j];
        int len   = end - start;

        string seg;
        if (len > 0) {
            seg = v1.substr(start, len);
        } else {
            seg = "0";
        }

        valores[j] = stoi(seg);
        prev = end;
    }
    int n1 = contador + 1;


    vector<int> indicesPuntosSeg(v2.length() + 1, 0);
    vector<int> valoresSeg(v2.length() + 1, 0);

    int contadorSeg = 0;
    for (int i = 0; i < (int)v2.length(); i++) {
        if (v2[i] == '.') {
            indicesPuntosSeg[contadorSeg] = i;
            contadorSeg++;
        }
    }
    indicesPuntosSeg[contadorSeg] = (int)v2.length();

    prev = -1;
    for (int j = 0; j <= contadorSeg; j++) {
        int start = prev + 1;
        int end   = indicesPuntosSeg[j];
        int len   = end - start;

        string seg;
        if (len > 0) {
            seg = v2.substr(start, len);
        } else {
            seg = "0";
        }

        valoresSeg[j] = stoi(seg);
        prev = end;
    }
    int n2 = contadorSeg + 1;


    int n;
    if (n1 > n2) n = n1;
    else n = n2;

    for (int j = 0; j < n; j++) {
        int a, b;
        if (j < n1) a = valores[j];
        else a = 0;

        if (j < n2) b = valoresSeg[j];
        else b = 0;

        if (a > b) return 1;
        if (a < b) return -1;
    }
    return 0;
}
