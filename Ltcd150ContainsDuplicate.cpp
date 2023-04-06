#include <vector>
#include <algorithm>
using namespace std;

// Given an array nums of integers, find if any value appears more than once

// This is the most basic if not the first coding exercise anyone comes across.
// The most straightforward and powerful solution is to just sort the array, so that all values follow each other increasingly.
// Fortunately every single language, including C++, have a sort method already implemented for us.
// Then we can just search in O(n) time the array, and if we find two following values with the same value, then there is a duplicate.

class BestSolution
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] == nums[i + 1])
                return true;
        }
        return false;
    }
};