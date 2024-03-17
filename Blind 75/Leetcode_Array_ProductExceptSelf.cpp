#include <vector>

using namespace std;

// EXPLANATION

// Given an array nums, return an array such that each element at index i is equal to the product of every number except the number at i.
// Example : [1,2,3,4], should return [24,12,8,6] which are the multiplications of every number of the array except the number at the same index.
// This solution should run in O(n) time and without the use of the division operator.

// This is complicated since the two obvious solutions are either to do a O(n2) double for loop in order to multiply everything except self, which is bad.
// Or, to multiply every numbers once, then divide them each by the number at the index, in order to get the result, which is O(n).
// But in cases where there are zeros in the array, the division starts to get very problematic, hence this solution.

// The idea here is to use a logic of prefix and postfix multiplication, meaning that each product really is the product of what is before the number and what is after the number.
// Knowing that, we can go through the array twice, in normal then in reverse order, and calculate the prefix and postfix as we go, and registering them directly in the result array,
// to avoid using more memory than is necessary.
// What we do is we first add the prefix inside the result array, on the first pass, then we multiply with the postfix inside the result array, on the second pass.
// The way we avoid the actual number is quite easy, we initialize the fixes at 1, then we first register that fix in the result array as the fix for the current number,
// and only afterwards do we multiply it with the current number, which will then serve as the fix for the next number. Therefore the end (or start) numbers of the array will just be ignored.

// This is the correct solution, where we traverse from one side then from the other, calculating the prefix and postfix as we go for each number, and multiplying everything in the result array.

class Solution {
public:

    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int> result = vector<int>(nums.size());

        int fix = 1;
        for (int i =  0; i < nums.size(); ++i)
        {
            result[i] = fix;
            fix *= nums[i];
        }
        fix = 1;
        for (int j = nums.size() - 1; j >= 0; --j)
        {
            result[j] *= fix;
            fix *= nums[j];
        }

        return result;
    }
};