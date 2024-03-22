#include <vector>
#include <algorithm>

using namespace std;

// EXPLANATION

// Given an array nums of integers, find if any value appears more than once

// This is the most basic if not the first coding exercise anyone comes across.
// The most straightforward and powerful solution is to just sort the array, so that all values follow each other increasingly.
// Fortunately every single language, including C++, have a sort method already implemented for us.
// Then we can just search the array, and if we find two following values with the same value, then there is a duplicate.

// This runs in O(n) time and in O(1) space

class Solution {
public:

    bool containsDuplicate(vector<int>& nums)
    {
        if (nums.size() <= 1)
            return false;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] == nums[i + 1])
                return true;
        }
        return false;
    }
};

class OtherSolution {
public:

    bool containsDuplicate(vector<int>& nums)
    {
        if (nums.size() <= 1)
            return false;

        sort(nums.begin(), nums.end());

        int x = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == x)
                return true;
            x = nums[i];
        }
        return false;
    }
};