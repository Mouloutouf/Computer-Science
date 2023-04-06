#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

// Given an array nums of integers and a target value, find the two values that add up to target. There is exactly one solution for each array.

// Basic and bad O(n2) solution, where we compare every value in the array with each other until we find a pair that adds up to target, then return their indexes.
// Memory is O(1) though.

class BadSolution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            int val = nums[i];
            for (int j = 0; j < nums.size(); ++j)
            {
                if (j != i && val + nums[j] == target)
                    return {i, j};
            }
        }
        return {};
    }
};

// Better O(n) solution, using a map to store each value we come across, then for each value, substract the target, and then search for the remainder inside the map.
// If it is present, then a previous value can be matched to add up to target, in which case we return their indexes.
// Memory is O(n).

class BestSolution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        map<int, int> map;
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i)
        {
            int remainder = target - nums[i];
            if (map.find(remainder) != map.end())
                return {map[remainder], i};
            
            map[nums[i]] = i;
        }
    }
};