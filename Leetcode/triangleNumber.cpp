/*
*
*   @author : Santiago Garcia Dominguez
*   @date   : 26/09/2025
*/

#include <iostream>
#include <vector>

using namespace std;
int triangleNumber(vector<int> nums);
int main(){

    vector<int> sample ={2,10,2,10,2};
    int sol = triangleNumber(sample);
    cout << "Solucion : " << sol << endl;
    return 0;
}
int triangleNumber(vector<int> nums){
    
    //bb sort
    for(int i = 1; i < nums.size(); i++){
        for(int j = 0; j < nums.size()-i; j++){
            if(nums[j] > nums[j+1]){
                int temp = nums[j+1];
                nums[j+1] = nums[j];
                nums[j] = temp;
            }
        }
    }
    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << endl;
    }
    int pointerIndex = nums.size()-1;
    int counter = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i+1; j < nums.size(); j++) {
            for (int k = j+1; k < nums.size(); k++) {
               if (nums[i] + nums[j] > nums[k]) {
                    counter++;
                }
            }
        }
    }


    return counter;
}