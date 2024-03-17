#include <vector>

using namespace std;

// TODO IMPORTANT

// /!\ I don't completely understand this solution
// This is quite complicated to grasp but it is a fairly easy and straightforward problem

class Solution {
public:

    int rob(vector<int>& nums)
    {
        int robFirst = 0;
        int robNext = 0;

        for (int n : nums)
        {
            int robMax = max(robFirst + n, robNext);
            robFirst = robNext;
            robNext = robMax;
        }
        return robNext;
    }
};