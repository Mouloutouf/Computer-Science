#include <vector>
#include <algorithm>
using namespace std;

// EXPLANATION

// Given a list of intervals, return that same list but with overlapping intervals merged.

// The solution is quite straightforward.
// First, we just sort that list, so that we have all intervals in increasing start order.
// Then we can go through all the intervals, starting at the second one, and systematically check with the previous interval to see if they are overlapping.
// If they are, then we modify the previous interval end value (directly in the result list) by taking the maximum value between its own end, or the end of the overlapping interval.
// Otherwise, we just add the interval to the result, and continue with our loop.
// Once we have checked all intervals, we can return the result.

class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i)
        {
            int n = result.size();
            int lastEnd = result[n - 1][1];

            if (lastEnd >= intervals[i][0])
                result[n - 1][1] = max(lastEnd, intervals[i][1]);
            else
                result.push_back(intervals[i]);
        }

        return result;
    }
};