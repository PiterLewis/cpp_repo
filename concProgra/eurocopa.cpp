#include<iostream>
using namespace std;
char calcular_ganador(char *equipos, int inicio, int n, int ronda)
{
	/*función divide y vencerás*/
	// caso base:
	if(inicio == n){
		//caso base hay una letra na mas
		return equipos[inicio]; //devolvemos la letra
	}
	
	int medio = (inicio + n) / 2;
	//dividir
	char resIz = calcular_ganador(equipos, inicio, medio, ronda+1);
	char resD = calcular_ganador(equipos, medio+1, n, ronda+1);
	
	char ganador;
	//lógica de rondas
	if(ronda % 2 == 0){
		ganador = resIz;
	}else{
		ganador = resD;
	}
	cout << "Ronda " << ronda << "Ganador : " << ganador;
	
	return ganador;
}

int main(){
	
 int n;
 cin >> n;
 char *equipos = new char[n+1];
 for(int i = 0;i <n; i++)
	equipos[i]='A'+i;
 equipos[n]=0;
 
 char res = calcular_ganador(equipos, 0, n-1, 0);
 cout << "Ganador total : " << res;

}