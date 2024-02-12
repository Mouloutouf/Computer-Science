#include <vector>

using namespace std;

// TODO
// Here we try to find the min value of the array using binary search. The array can be rotated, meaning it may be split in two parts.
// We use the binary search in order to know in which part of the array we are. Whenever we find ourselves within a sorted portion, we try to update the minimum value.
// Otherwise we just continue with the binary search until we find the minimum value.
// This runs in O(logn) time

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