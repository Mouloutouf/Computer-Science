#include <vector>
#include <algorithm>
using namespace std;

class Interval {
public:

    int start, end;

    Interval(int start, int end)
    {
       this->start = start;
       this->end = end;
    }
};

// EXPLANATION

// Given a list of intervals representing meetings, return whether it is possible to attend all meetings or not.

// This is a very straightforward and the most basic interval problem.
// The solution is to sort the intervals so they are all in increasing start order. Then we just have to loop to check if the current interval overlaps the previous one,
// in which case, we return false. Otherwise we reach the end and return true.

class Solution {
public:

    bool canAttendMeetings(vector<Interval>& intervals)
    {
        struct { bool operator()(Interval& a, Interval& b) const { return a.start < b.start; } } compareStarts;

        sort(intervals.begin(), intervals.end(), compareStarts);

        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i].start < intervals[i - 1].end)
                return false;
        }
        return true;
    }
};