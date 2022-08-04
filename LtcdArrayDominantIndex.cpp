#include <vector>
using namespace std;

// Given an Array nums, Find the Largest Element in the Array, then Check if it is at least Twice as Big as every Other Element in the Array. If so, return its Index,
// Otherwise return -1

// First Solution is quite easy. First Loop to find the Largest Element. Then Second Loop to Compare with Other Elements.

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max = 0;
        for (int i = 1; i < nums.size(); ++i){
            if (nums[i] > nums[max]){
                max = i;
            }
        }
        for (int j = 0; j < nums.size(); ++j){
            if (j != max && nums[j] * 2 > nums[max]){
                return -1;
            }
        }
        return max;
    }
};

// Second Solution is quite smart. We loop only once to find the largest element and also track the second largest element.
// If the largest element is not twice as big as the second largest element, then it is not twice as big as every other element in the array.
// The else if statement is for when the maximum has been reached, but since we continue to iterate through the loop we need to be sure if there
// might not be a larger second maximum down the road.

class BetterSolution {
public:
    int dominantIndex(vector<int>& nums) {
        int pmx = 1;
        int mx = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[mx]) {
                pmx = mx;
                mx = i;
            }
            else if (nums[pmx] < nums[i]) {
                pmx = i;
            }
        }
        if (nums[mx] >= 2 * nums[pmx]) {
            return mx;
        }
        return -1;
    }
};