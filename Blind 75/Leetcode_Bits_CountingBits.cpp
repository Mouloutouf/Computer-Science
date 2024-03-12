#include <vector>

using namespace std;

// TODO

// This is some dynamic programming shit, it's pretty good

class Solution {
public:

    vector<int> countBits(int n)
    {
        vector<int> dp(n + 1, 0);
        
        int b = 1;

        for (int i = 1; i <= n; ++i)
        {
            if (b * 2 == i)
                b = i;
            
            dp[i] = 1 + dp[i - b];
        }
        return dp;
    }
};