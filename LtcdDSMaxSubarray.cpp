#include <vector>
using namespace std;

// Given an Array nums of Integers, find the Subarray that has the largest sum.
// The Solution is to go through the Array, and continue to add the values to a certain sum, and update the max accordingly.
// If the sum ever goes below 0, reset it to 0. Which I don't quite understand, especially for Arrays with only negative numbers.
// Then return the max found.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            if (sum > max){
                max = sum;
            }
            if (sum < 0){
                sum = 0;
            }
        }
        return max;
    }
};