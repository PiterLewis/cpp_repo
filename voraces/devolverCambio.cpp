/*
@author Santiago Garcia Dominguez
Fecha : 09/03/2025
*/
#include <iostream>
using namespace std;

int main() {
    int pProducto; // Cantidad a devolver
    int precios[] = {5, 2, 1}; // Monedas disponibles (ordenadas de mayor a menor)
    int cantidadMonedas[3] = {0, 0, 0}; // Para almacenar cuántas de cada moneda se usan

    cout << "Ingrese la cantidad a devolver: ";
    cin >> pProducto;

    for (int i = 0; i < 3; i++) {
        cantidadMonedas[i] = pProducto / precios[i]; // Cantidad de monedas de este tipo
        pProducto %= precios[i]; // Reducimos el total con el cambio dado
    }

    cout << "Monedas usadas:\n";
    cout << "5: " << cantidadMonedas[0] << " | 2: " << cantidadMonedas[1] << " | 1: " << cantidadMonedas[2] << endl;

    return 0;
}
