#include <vector>

using namespace std;

// TODO

class Solution {
public:

    int uniquePaths(int m, int n)
    {
        // initialize the base row to all ones
        vector<int> row(n, 1);

        // for each row in the grid (starting at 1 since we already have the last row)
        for (int i = 1; i < m; ++i)
        {
            // create a new row initialized to all ones
            vector<int> newRow(n, 1);

            // for each element in the row, replace each with the value in front of it + the value below it
            // start at n - 2 in order to keep the last element to 1, then walk backwards until all elements have been updated
            for (int j = n - 2; j >= 0; --j)
                newRow[j] = newRow[j + 1] + row[j];
            
            // update the bottom row to be the new row
            row = newRow;
        }
        // return the first value of the row, which will be the number of unique paths
        return row[0];
    }
};