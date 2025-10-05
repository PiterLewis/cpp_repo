/*
*   @author Santiago Garcia Dominguez 
*   Leetcode problem 'twoSum'
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int> &nums, int target) {
            for (int i = 0; i < nums.size(); i++) {
                for (int j = i + 1; j < nums.size(); j++) {
                    if (nums[j] == target - nums[i]) {
                        return {i, j};
                    }
                }
            }
            
            return {};
        }
};

/*  SOLUCION: TABLA HASH DOS VUELTAS

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (hash.find(complement) != hash.end() && hash[complement] != i) {
                return {i, hash[complement]};
            }
        }
        // If no valid pair is found, return an empty vector
        return {};
    }
};

*/

/*  SOLUCION: TABLA HASH UNA VUELTA 

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (hash.find(complement) != hash.end()) {
                return {hash[complement], i};
            }
            hash[nums[i]] = i;
        }
        // Return an empty vector if no solution is found
        return {};
    }
};

*/