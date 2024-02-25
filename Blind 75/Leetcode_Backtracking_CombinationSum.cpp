#include <vector>

using namespace std;

// EXPLANATION

// Given an array of distinct integers and a target integer, return all possible combinations.

// It is said in the exercice that the test cases are made so that there is never more than 150 combinations for a certain input.
// This is important since this problem does not ask us to find these combinations more efficiently than with some typical brute force solution like in many other problems.
// As a matter of fact it is impossible to do this quickly, since finding all possible solutions does require us to go through every possibilities, there is no way around it.

// The problem's only thing we need to really take care of is making sure we only return combinations and not permutations.
// Since for instance a combination of 2,2,3 which gives 7 has permutations 3,2,2 and 2,3,2, but we do not need to return those, only one of them.
// Therefore we will need to reduce the combination possibilities as we go through the array (this will indeed make the search more performant but it is not really the point here).

// The main idea is to do this recursively and progress through the array with two possible options to progress every time.
// The first option, is to add the current number to the total.
// The second option, is to change the current number to the next number.
// Whenever we match the target, we add our current combination to the result then return.
// Whenever we overshoot the target or our current number goes out of range, we cannot continue, therefore we return.
// By doing so, and making both decisions at every time recursively, essentially giving us a binary tree kind of progress,
// we make sure we end up adding up every number of the array, but never repeating a number.
// For instance if at some point, we have the combination 2,3 then it is impossible for us to get the combination 2,3,2, since 2 was already added and we are now looking at current number = 3.
// By the end we'll have found all combinations, in order. (In order meaning that for instance if the input array is sorted, then all combinations will be in increasing order).

// Here, we cannot really make the base result method recursive, so we have to make another method for that, but since we are in C++ we cannot make this method inside of the other,
// so we therefore need to pass all of the information inside the recursive method, so it's got a shitload of parameters but that's fine.

// IMPORTANT

// /!\ This solution is not runtime nor memory efficient in C++, got to look into that

class Solution {
public:

    void solve(vector<vector<int>>& result, vector<int>& candidates, int target, int i, vector<int> current, int total)
    {
        // Found target
        if (total == target)
        {
            result.push_back(vector<int>(current.begin(), current.end()));
            return;
        }
        // Cannot continue
        if (i >= candidates.size() || total > target)
            return;

        // Continue adding the same number
        current.push_back(candidates[i]);
        solve(result, candidates, target, i, current, total + candidates[i]);

        // Change the number
        current.pop_back();
        solve(result, candidates, target, i + 1, current, total);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> result = vector<vector<int>>();

        vector<int> current = vector<int>();
        int i = 0;
        int total = 0;

        solve(result, candidates, target, i, current, total);

        return result;
    }
};