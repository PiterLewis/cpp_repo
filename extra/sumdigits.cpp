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

    if(x < 10){
        
        return x;
    }else{
        return (x % 10)  + conteo(x / 10);
    }
  
}