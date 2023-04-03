#include <iostream>
#include <vector>
#include <algorithm>

// W.I.P

int RequiredRooms(std::vector<std::pair<int, int>> intervals)
{
    if (intervals.size() == 0)
        return 0;

    std::sort(intervals.begin(), intervals.end());

    std::vector<int> thresholds;
    int rooms = 1;
    for (int i = 0; i < intervals.size(); ++i)
    {
        for (int j = 0; j < thresholds.size(); ++j)
        {
            if (intervals[i].first >= thresholds[j])
                break;

            rooms++;
        }
        
        thresholds.push_back(intervals[i].second);
    }
}