#include <vector>
#include <map>

using namespace std;

// EXPLANATION

// Given a list of coins of different values and an amount, determine the minimum amount of coins necessary to reach that amount.
// If it is impossible to reach the amount with the given coins, then return -1.

// The idea here is to go through each possible amount, from 1 to the actual amount, and compute the minimum number of coins for each of these amounts,
// and then register these numbers of coins inside of the dp, which will in turn be used to determine the minimum number of coins of the upcoming amounts, as our loop continues towards higher amounts.
// By the end of the loop, we will have found the minimum number of coins necessary to make the final amount.
// Or, if no combination of coins gets us to the amount, the final amount will remained unchanged from its default value, hence we can return -1.

class Solution {
public:

    int coinChange(vector<int>& coins, int amount)
    {
        // set the dp to have exactly amount + 1 elements (0 -> amount inclusive), all set to amount + 1 value (default maximum value)
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        // go through each possible amounts,
        for (int a = 1; a <= amount; ++a)
        {
            // and check for each type of coin,
            for (int c : coins)
            {
                // if you can add that coin without overshooting.
                // If that is the case, then first retrieve the minimum number of coins that add up to the remainder of : amount - coin, and add 1 for the current coin,
                // and then set the minimum number of coins of that amount to be the smallest value between : our current number of coins (itself), or, the newly computed number of coins
                // The reason we check for the minimum is because, for that amount, we may have already found a smaller coin combination prior, and the newly computed combination,
                // with the specific coin that is being checked may not be a better combination. (if the coin that is checked is smaller for instance, hence the retrieved number of coins may be bigger)
                if (a - c >= 0)
                    dp[a] = min(dp[a], 1 + dp[a - c]);
            }
        }
        
        // if the dp for the final amount is different from the default maximum value, then we have found the amount of coins necessary to reach the amount, so we can return it
        if (dp[amount] != amount + 1)
            return dp[amount];
        // otherwise, we could not find a way to add the coins up to the amount, so return -1
        else
            return -1;
    }
};