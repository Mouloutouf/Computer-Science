#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// Sometimes you really don't need to bother when doing a Leetcode exercise
// Just use the standard library sorting algorithm and call it a day

// Height Checker :
// Sort everyone by height, then check the discrepencies between the first given list, heights, and the sorted list

// Quickest Solution
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int result = 0;
        
        vector<int> sorted(heights);
        sort(sorted.begin(), sorted.end());
        
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != sorted[i]) {
                result++;
            }
        }
        return result;
    }
};

// WIP Shit Exercise
// Want to tear my balls off

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int f = INT_MIN, s = INT_MIN, t = INT_MIN;
        int m = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == f || nums[i] == s || nums[i] == t) {
                continue;
            }
            if (nums[i] > f) {
                t = s;
                s = f;
                f = nums[i];
                m++;
            }
            else if (nums[i] > s) {
                t = s;
                s = nums[i];
                m++;
            }
            else if (nums[i] > t) {
                t = nums[i];
                m++;
            }
        }
        if (m >= 3) {
            return t;
        }
        else {
            return f;
        }
    }
};