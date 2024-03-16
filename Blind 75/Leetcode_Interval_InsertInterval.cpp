#include <vector>
using namespace std;

// EXPLANATION

// Given a list of intervals of type [start, end] sorted by increasing start order, and a new interval, insert the new interval inside the list.
// You have to merge overlapping intervals if there are any.

// This is actually quite straightforward, we need to add the intervals into a result array, and merge the intervals overlapping our new interval as we go, then return.

// Loop through all the intervals.
// If the interval is before the new interval, just add it to the result.
// If the interval overlaps, meaning the start element of the new interval is inside the previous interval, or the end element of the new interval is inside the next interval
// Then change the new interval start and/or end element to match the previous interval start and/or next interval end.
// Afterwards, add the new merged interval to the result.
// If the interval is after the new interval, just add it to the result.
// Return the result.

class Solution {
public:

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        if (intervals.empty() == true)
            return { newInterval };

        vector<vector<int>> result;
        bool inserted = false;

        for (int i = 0; i < intervals.size(); ++i)
        {
            // new interval is after current interval
            if (newInterval[0] > intervals[i][1]){
                result.push_back(intervals[i]);
            }

            // new interval start is inside current interval
            if (newInterval[0] <= intervals[i][1] && newInterval[0] >= intervals[i][0]){
                newInterval[0] = intervals[i][0];
            }
            // new interval end is inside current interval
            if (newInterval[1] >= intervals[i][0] && newInterval[1] <= intervals[i][1]){
                newInterval[1] = intervals[i][1];
            }

            // if new interval is not inserted and we are at the end of the list or before the current interval
            if (inserted == false && (i == intervals.size() - 1 || newInterval[1] < intervals[i][0])){
                result.push_back(newInterval);
                inserted = true;
            }

            // new interval is before current interval
            if (newInterval[1] < intervals[i][0]){
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};

// This is a more elegant solution, does not require a boolean, we just chain three whiles for the three steps of the program

class OtherSolution {
public:

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        vector<vector<int>> result;

        int i = 0;
        int n = intervals.size();

        // while we are before the new interval
        while (i < n && intervals[i][1] < newInterval[0])
        {
            result.push_back(intervals[i]);
            i++;
        }

        // while the new interval overlaps
        while (i < n &&  intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;

        }
        // Add it once overlap is finished
        result.push_back(newInterval);

        // while there are intervals left
        while (i < n)
        {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};