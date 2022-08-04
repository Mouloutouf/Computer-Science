#include <vector>
using namespace std;

// Given an Array of nums, Find the index such that the sum of all elements strictly to the right equals the sum of all elements strictly to the left, return this index.
// If there is no index that satisfies this condition, return -1.

// The most straightforward way of doing this, would be to iterate through all elements in the array, and then iterate again to calculate the sum of the rightmost elements
// while updating the sum of the leftmost elements, as we iterate through our array. We would then compare, at each iteration, our right sum and left sum, to find the pivot.
// But this is costly and unnecessary, and gives us a O(n2) solution.
// The correct solution, that is O(n), is to first iterate through the list to calculate the total sum of our array. Then iterate again, and while updating our left sum,
// then check, by subtracting our left sum from our total sum as well as the value of the current element (since pivot's value should not be taken into account).
// This gives us our right sum. And then, we can compare, if left sum equals right sum, e.g. our calculation, and return the pivot. Otherwise we continue to iterate.

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum = 0;
        int totalSum = 0;
        for (int j = 0; j < nums.size(); ++j){
            totalSum += nums[j];
        }
        for (int i = 0; i < nums.size(); ++i){
            if (totalSum - nums[i] - leftSum == leftSum){
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};