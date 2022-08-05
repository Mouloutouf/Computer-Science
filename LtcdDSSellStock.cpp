#include <vector>
using namespace std;

// Given an Array prices of Integers where each Element represents the Price of a Stock on a given Day
// Return the Maximum Profit that can be made from Buying the Stock on a certain Day and Selling it on another Day in the Future
// Essentially, given this Array, find the Biggest Value Gap in its Elements
// So you just have to Check for Two Things.
// First, is the Minimal Value. Updated every time you Find a Smaller Value in the Array.
// Second, is the Maximum Value from the Subtraction of the Minimal Value and the Current Value. Every time you Find a Bigger Result, update the Maximum Value.
// That's it. Then return your Maximum Value, e.g. your Profit.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int buy = INT_MAX;
        for (int i = 0; i < prices.size(); ++i){
            if (prices[i] < buy){
                buy = prices[i];
            }
            if (prices[i] - buy > max){
                max = prices[i] - buy;
            }
        }
        return max;
    }
};