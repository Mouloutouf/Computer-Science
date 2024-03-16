#include <vector>
#include <algorithm>
using namespace std;

// EXPLANATION

// Given a list of intervals of type [start, end], return the minimum amount of removals necessary for all intervals to be non-overlapping.

// This algorithm is actually quite simple and uses the simple rule of greedy algorithms in order to, in this case, minimize the number of removals.

// First, we should sort the intervals, this is almost always necessary for these kinds of problems, as it allows us to compare the intervals
// as we go through the loop in ascending order, and therefore allows us to check for overlaps.
// Once the list is sorted we can just go through the list, to check for overlaps. We just need a reference to the end value of the previous interval,
// and compare it to the start value of the current interval to know if we have an overlap.
// If we do have an overlap, we now have to remove one of the two intervals. We don't actually remove the interval from the list, we just increment our result
// and set the next end value to the end value of the interval we decide to keep.
// In order to decide which interval to keep, very simple, we keep the one that has the smallest end value, since it will be less likely to overlap with other intervals.
// This is a greedy algorithm technique, where we check for likeliness in order to make a decision and maximize our outcome (here minimize it).

class Solution {
public:

    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end());

        int result = 0;

        int lastEnd = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i][0] >= lastEnd)
                lastEnd = intervals[i][1];
            else
            {
                result++;
                lastEnd = min(intervals[i][1], lastEnd);
            }
        }
        return result;
    }
};