/*
*   @author : Santiago García Domínguez
*   @date   : 27/09/2025
*   @description: Given an integer array nums, return the largest perimeter of a triangle with a non-zero area
*   formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0. 
*/

#include <iostream>
#include <vector>

using namespace std;
int largestPerimeter(vector<int>& nums);
int main(){
    vector<int> nums = {6,5,3,1,2,9,10};
    int sol = largestPerimeter(nums);
    cout << sol << endl;
    return 0;
}
int largestPerimeter(vector<int>& nums){
    
    for(int i=0; i<nums.size(); i++){
            for(int j=0;j<nums.size()-i-1; j++){
                if(nums[j] > nums[j+1]){
                    int temp=nums[j];
                    nums[j]=nums[j+1];
                    nums[j+1]=temp;
                }
        }
    }

    //agrupar por conjuntos
    int pointerIndex = (int)nums.size() - 1;
    while (pointerIndex >= 2) {
        int i = pointerIndex - 1, j = pointerIndex - 2;
        if (nums[i] + nums[j] > nums[pointerIndex]){ 
            return nums[i] + nums[j] + nums[pointerIndex];
        }
        --pointerIndex;
    }

    return 0;
    
}