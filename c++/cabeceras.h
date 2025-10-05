// primera cabecera que guarde los nombres
// segunda cabecera imprima por pantalla la matriz

#define MAX_TAM 100
#define MAX_NOMBRES 4
void pedirNombres();
void guardarNombres(char*& nombre);
void crearMatriz(char**& matrix);
void printMatrix(char** matrix);
void liberarMatrix(char **matrix, int filas);