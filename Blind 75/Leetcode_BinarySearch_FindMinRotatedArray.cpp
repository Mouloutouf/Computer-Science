#include <vector>

using namespace std;

// EXPLANATION

// Given an array of size n sorted in ascending order, and that has been rotated (or pushed) 1 to n times, find the minimum value of that array.
// Rotated means this : original array [0,1,2,3], same array rotated 2 times [2,3,0,1]. The numbers are essentially pushed and come back on the other side.
// if the array is rotated exactly n times, then it goes back to being the exact same array, since all numbers have been pushed and came back to their original place.
// /!\ Very Important, this code must run in O(logn) time, this means the problem should be solved with a binary search essentially.

// The idea here is that with a binary search, we will start at the middle then decide whether to continue searching on the left or the right side.
// At the very beginning of our search, one of two things can happen. We either are in the biggest part of the array, or in the lowest part.
// Depending on this observation, we can then know where to search.
// To check where we are in this array, we just need to look at the first and last value. If our current value is smaller than the last value, we are in the lowest part,
// if our current value is bigger than the first value, we are in the biggest part. And if its both, then the array has been rotated n times and is unchanged, we can just return the first value.
// Given where we are, if we are in the biggest part, then we should search right, in order to try and end up in the lowest part, where the minimum value is.
// If we are in the lowest part already, we can search left, in order to end on the minimum value.

class Solution {
public:

    int findMin(vector<int>& nums)
    {
        int l = 0, r = nums.size() - 1;
        int result = nums[0];

        while (l <= r)
        {
            if (nums[l] < nums[r])
                return min(result, nums[l]);

            int m = (l + r) / 2;
            result = min(result, nums[m]);

            if (nums[m] >= nums[0])
                l = m + 1;
            else
                r = m - 1;
        }
        return result;
    }
};