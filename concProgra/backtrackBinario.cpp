#include <iostream>
using namespace std;
void backtracking(string combinaciones, int n);
int main(){
	
	int n;
	cin >> n;
	string combinaciones = "";
	backtracking(combinaciones, n); //tipo de estado¿? | estado actual¿?
	return 0;
}
void backtracking(string combinaciones, int n){
	//caso base: hay 3 dígitos y son distintos al anterior
	if(combinaciones.length() == n ){
		
		if(combinaciones[0] == '0' && combinaciones[n-1] == '0'){
			cout << combinaciones << endl;
		}
		return;
	}
	
	backtracking(combinaciones + "0", n);
	
	// Añadir '1' solo si el último no fue '1'
    int len = combinaciones.length();
    if (len == 0 || combinaciones[len - 1] != '1') {
        backtracking(combinaciones + "1", n);
    }
	
}


