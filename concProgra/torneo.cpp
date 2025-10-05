#include <iostream>
using namespace std;

char calcular_ganador(char* equipos, int inicio, int fin, int ronda) {
    cout << "Entrando en calcular_ganador(" << inicio << ", " << fin << ", ronda " << ronda << ")\n";

    if (inicio == fin) {
        cout << "Caso base: devuelvo " << equipos[inicio] << "\n";
        return equipos[inicio];
    }

    int medio = (inicio + fin) / 2;

    cout << "Llamo a la izquierda (" << inicio << " a " << medio << ")\n";
    char ganadorIzq = calcular_ganador(equipos, inicio, medio, ronda + 1);

    cout << "Volví de la izquierda con " << ganadorIzq << "\n";

    cout << "Llamo a la derecha (" << medio + 1 << " a " << fin << ")\n";
    char ganadorDer = calcular_ganador(equipos, medio + 1, fin, ronda + 1);

    cout << "Volví de la derecha con " << ganadorDer << "\n";

    char ganador;
    if (ronda % 2 == 0)
        ganador = (ganadorIzq > ganadorDer) ? ganadorIzq : ganadorDer;
    else
        ganador = (ganadorIzq < ganadorDer) ? ganadorIzq : ganadorDer;

    cout << "Ronda " << ronda << ": comparo " << ganadorIzq << " y " << ganadorDer << "  gana " << ganador << "\n";
    return ganador;
}

int main() {
    char equipos[2] = {'A', 'B'};
    char campeon = calcular_ganador(equipos, 0, 1, 0);
    cout << "\n Campeon final: " << campeon << endl;
    return 0;
}
