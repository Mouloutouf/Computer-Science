#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// My Solution
// Best Solution

// Sort Array by Parity so that all pair elements are at the front of the array and all odd elements are at the end of the array

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int p = 0;
        // Go through the array once
        for (int i = 0; i < nums.size(); ++i) {
            // If the element is pair, swap it with the element at index p
            if (nums[i] % 2 == 0) {
                // Perform the swap
                int t = nums[p];
                nums[p] = nums[i];
                nums[i] = t;
                // Increase p
                p++;
            }
        }
        return nums;
    }
};