/*
*
*   @author : Santiago Garcia Dominguez
*   @date   : 26/09/2025
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int triangleNumber(vector<int> nums);
int main(){

    vector<int> sample ={2,10,2,10,2};
    int sol = triangleNumber(sample);
    cout << "Solucion : " << sol << endl;
    return 0;
}

int triangleNumber(vector<int> nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int count = 0;

    for (int k = n-1; k >= 2; k--) { 
        int i = 0, j = k-1;
        while (i < j) {
            if (nums[i] + nums[j] > nums[k]) {
                count += (j - i);
                j--;
            } else {
                i++;
            }
        }
    }

    return count;
}
