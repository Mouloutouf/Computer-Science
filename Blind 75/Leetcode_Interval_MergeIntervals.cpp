#include <vector>
#include <algorithm>
using namespace std;

// TODO

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