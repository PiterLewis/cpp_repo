/*
*   @author: Santiago García Domínguez
*   @date  : 01/10/2025
*   @description: Solution to the "bottle" problem using greedy.
*/

#include <iostream>

using namespace std;
int numWaterBottles(int numBottles, int numExchange);
int main(){
    int btts=15;
    int numEx=4;

    int sol = numWaterBottles(btts, numEx);
    cout << sol << endl;
    return 0;
}
int numWaterBottles(int numBottles, int numExchange) {
    int initialAmount = numBottles;
    int empties = numBottles;
    
    while(empties >=numExchange){
        int newBottles = empties/numExchange;
        initialAmount +=newBottles;
        empties = newBottles + (empties % numExchange);
    }

    return initialAmount;
}
