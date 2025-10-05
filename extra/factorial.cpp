#include <iostream>
#define MAX_TAM 10
using namespace std;
int factorial(int x);

int main(){

    int numerin = 5;
    int res = 0;

    res = factorial(numerin);
    cout << res << endl;

}

int factorial(int x){

    //caso base cuando x = 0 o x = 1 el fact es 1. 
    if(x <= 1){
        return 1;
    }else{
    //x por factorial de x - 1.
        return x * factorial(x-1);
    }
}