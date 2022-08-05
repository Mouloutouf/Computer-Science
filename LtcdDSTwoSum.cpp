#include <vector>
#include <unordered_map>
using namespace std;

// Given an Array nums of Integers and a Target Value, find the Two Values that Add up to Target. There is exactly one solution for each Array.

// Basic O(n2) solution

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i){
            int val = nums[i];
            for (int j = 0; j < nums.size(); ++j){
                if (j != i && val + nums[j] == target){
                    return vector<int> {i, j};
                }
            }
        }
        return vector<int>();
    }
};

// Better O(n) solution, using Hash Map. Don't understand it yet

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> result;
        for (int i=0; i<nums.size(); i++)
        {
            int need = target - nums[i];
            if ( hash.find(need) != hash.end())
            {
                result.push_back(hash[need]);
                result.push_back(i);
                return result;
            }
            hash[nums[i]] = i;
        }
        return result;
    }
};