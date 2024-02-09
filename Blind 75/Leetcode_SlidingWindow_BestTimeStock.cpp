#include <vector>

using namespace std;

// EXPLANATION

// Given an array prices of integers where each element represents the price of a stock on a given day
// return the maximum profit that can be made from buying the stock on a certain day and selling it on another day in the future

// Essentially, given this array, find the biggest value delta in its elements.

// Since this array represents prices over time, then we only need to find a delta in increasing order of the array.
// Therefore, we can just go through the array normally, and check as we go along, how this delta evolves.
// We just need to check for two things, the minimum value, and the maximum delta.

// Everytime we find a value that is smaller than our minimum value, we replace it.
// And everytime we find a delta, meaning a price that is subtracted to our min value, that is higher than our current one, we replace it.
// We then return our max delta.

// This works since, everytime we find a smaller min value, even though we could continue and potentially get a higher delta in the future with our current value,
// then we would make an even higher delta from having a smaller min value. And if we do not get a higher delta, then we have already reached our max delta before,
// and can replace our min value anyway since we won't need it anymore.

class Solution {
public:

    int maxProfit(vector<int>& prices)
    {
        int max = 0;
        int buy = INT_MAX;

        for (int i = 0; i < prices.size(); ++i)
        {
            if (prices[i] < buy)
                buy = prices[i];

            if (prices[i] - buy > max)
                max = prices[i] - buy;
        }

        return max;
    }
};