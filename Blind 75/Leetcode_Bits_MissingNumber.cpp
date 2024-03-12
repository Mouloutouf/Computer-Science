#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// EXPLANATION

// Given an array nums of size n, with numbers ranging from 0 to n, find the missing number.

// Good O(2n) solution with O(1) memory
// Very straightforward, we just add up all numbers from 0 to n, then subtract all nums from the array, you get the missing number.

class Solution {
public:

    int missingNumber(vector<int>& nums)
    {
        int result = 0;

        for (int i = 0; i <= nums.size(); ++i)
            result += i;
        
        for (int i = 0; i < nums.size(); ++i)
            result -= nums[i];

        return result;
    }
};

// Better, runs in 0(n). We just do one loop instead of two, and start the result directly at value n.

class VariantSolution {
public:

    int missingNumber(vector<int>& nums)
    {
        int result = nums.size();

        for (int i = 0; i < nums.size(); ++i)
            result += i - nums[i];

        return result;
    }
};

// Solution with Bit Manipulation and the XOR operator

class BitSolution {
public:

    int missingNumber(vector<int>& nums)
    {
        int result = nums.size();

        for (int i = 0; i < nums.size(); ++i)
            result ^= i ^ nums[i];
        
        return result;
    }
};