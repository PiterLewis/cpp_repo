/*
    LEETCODE PROBLEM : 3005. Count Elements With Maximum Frequency
    @author : Santiago García Domínguez
    @date   : 22/09/2005

*/

#include <iostream>
#include <vector>

using namespace std;

int maxFrequencyElements(vector<int> &nums);

int main(){

    vector<int> numeros = {42,29,100,55,70,28,63,78,4,73,32,2,98,22,
        78,64,43,28,90,42,100,56,85,32,39,
        54,33,27,7,68,4,77,81,71,49,39,76,95,37,7,2};

    int sol = maxFrequencyElements(numeros);
    cout << "solucion : " << sol;
}

int maxFrequencyElements(vector<int> &nums){
    
    int numeros[100] = {0};

        int index = 0;

        for(int i = 0; i<nums.size(); i++){
            index = nums[i] - 1;
            numeros[index] += 1; 
        }

        
        int mayor = 0;
        int acumulador = 0;
        
        for(int j = 0; j<100; j++){
            
            if(mayor < numeros[j]){
                mayor = numeros[j]; 
                acumulador = numeros[j];
            }else if(mayor == numeros[j]){
                acumulador += numeros[j];
            }
            
        
        }

        return acumulador;
    }

