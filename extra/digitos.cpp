#include <iostream>
#define MAX_TAM 10
using namespace std;
int conteo(int x);

int main(){

    int numerin = 12345;
    int res = 0;

    res = conteo(numerin);
    cout << res << endl;

}

int conteo(int x){

    //caso base:
    if(x < 10){ // x por ejemplo es 12, da otra vuelta, si es 9 no
        return 1;
    }else{
        // por ejemplo conteo de 12 tiene que dar 1 + conteo de 12/10 = 1.2, ya menor a 10.
        return 1 + conteo(x / 10);
    }
  
}