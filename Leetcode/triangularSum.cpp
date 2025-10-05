/*
*   @author: Santiago Garcia Dominguez
*   @date  : 30/09/2025
*   @description : You are given a 0-indexed integer array nums, where nums[i] is a digit between 0 and 9 (inclusive).
*
*   The triangular sum of nums is the value of the only element present in nums after the following process terminates:
*
*   Let nums comprise of n elements. If n == 1, end the process. Otherwise, create a new 0-indexed integer array newNums of length n - 1.
*   For each index i, where 0 <= i < n - 1, assign the value of newNums[i] as (nums[i] + nums[i+1]) % 10, where % denotes modulo operator.
*   Replace the array nums with newNums.
*   Repeat the entire process starting from step 1.
*/

#include <iostream>
#include <vector>
using namespace std;

int triangularSum(vector<int> nums);
int main(){

    vector<int> mivector = {0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9};
    int sol = triangularSum(mivector);
    cout << sol << endl;

    return 0;
}
int triangularSum(vector<int> nums) {
    if(nums.size() == 1 ){
        return nums[0];
    }

    vector<int> newNums(nums.size()-1, 0);
    for(int i = 0; i<nums.size(); i++){
        for(int j =0;j<nums.size(); j++){
            //pasa una vez sumando
            newNums[j] = ((nums[j] + nums[j+1]) % 10);
        }
        nums = newNums;
    }
    return newNums[0];
}