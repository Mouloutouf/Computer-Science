#include <vector>
#include <string>

using namespace std;

// EXPLANATION

// See picture for problem description

// The idea here is to use two pointers in order to progress through the array and find the largest area possible.
// Since the area is calculated using length and height, we essentially want to maximize these two values.
// Hence we make our pointers start at each extremity of the array, to get the maximum length possible, for start.

// Then for each new position of our pointers, we calculate the area, and if it is greater than the max area we replace it.
// To progress our pointers we want to make sure we always have the highest possible heights.
// Therefore, we progress the pointer which has the lowest height, in order to keep our current max height intact until we find a bigger height.

// This way, we are able to progressively reduce our length while keeping/maximizing our height, and eventually find the largest possible area to contain water.

// This solution runs in O(n)

class Solution {
public:

    int maxArea(vector<int>& height)
    {
        int i = 0;
        int j = height.size() - 1;

        int max = 0;

        while (i < j)
        {
            int area = (j - i) * min(height[i], height[j]);

            if (area > max) max = area;
            
            if (height[i] <= height[j]) i++;
            else j--;
        }
        
        return max;
    }
};