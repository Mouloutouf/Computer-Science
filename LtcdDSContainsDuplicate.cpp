#include <vector>
#include <algorithm>
using namespace std;

// Given an Array nums of Integers, find if any Value appears more than once

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; ++i){
            if (nums[i] == nums[i + 1]){
                return true;
            }
        }
        return false;
    }
};