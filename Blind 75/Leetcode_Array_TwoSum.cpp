#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

// EXPLANATION

// Given an array nums of integers and a target value, find the two values that add up to target. There is exactly one solution for each array.

// Basic and bad O(n2) solution, where we compare every value in the array with each other until we find a pair that adds up to target, then return their indexes.
// Memory is O(1) though.

class BadSolution {
public:

    vector<int> twoSum(vector<int>& nums, int target)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 0; j < nums.size(); ++j)
            {
                if (j != i && nums[i] + nums[j] == target)
                    return {i, j};
            }
        }
        return {};
    }
};

// The solution here is to use a map in order to store the values and their indexes as we go along the list. And for each element in the list, subtract its value with the target,
// in order to find the delta or remainder necessary to reach the target. We then use map.find() in order to find that delta inside the map, and if we do, then we do have two values
// we can add up to target, we therefore return both the index of the value we subtracted from target, and the index of the delta value, which we already stored.

// This runs in O(n) time and in O(n) space

class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target)
    {
        map<int, int> map;

        for (int i = 0; i < nums.size(); ++i)
        {
            int r = target - nums[i];
            if (map.find(r) != map.end())
                return { map[r], i };
            
            map[nums[i]] = i;
        }

        return {};
    }
};