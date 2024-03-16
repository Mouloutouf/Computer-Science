#include <vector>
#include <algorithm>
using namespace std;

// EXPLANATION

// Given an array nums of integers, return the maximum possible sub array inside of nums

// This is a sliding window problem actually
// Here we need to go through the nums and keep increasing our sum, and if our sum is greater than our max sum, then replace it.
// The only thing that we actually need to do to make sure we only keep the best sequence of numbers, is to reset our sum to zero if it ever gets negative.
// Since the sum should not be negative, then we know if we ever get a sequence of numbers giving a negative sum, we can just cross this sequence and reset our search.

class Solution {
public:

    int maxSubArray(vector<int>& nums)
    {
        int maxSum = nums[0];
        int currentSum = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (currentSum < 0)
                currentSum = 0;
            
            currentSum += nums[i];
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};