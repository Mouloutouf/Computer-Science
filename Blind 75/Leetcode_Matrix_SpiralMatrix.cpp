#include <vector>
using namespace std;

// EXPLANATION

// Given a m x n matrix, return its elements in a spiral order.

// Here spiral order means we go through the matrix right, then down, then left, then up, and so on, until we reach the center, e.g. there are no more elements in the matrix
// The way we do this is quite simple, we keep track of 4 pointers, begin row, end row, begin column, and end column, and update them everytime we finish collecting
// the elements from a certain direction, essentially reducing our matrix search size as we go, until one of these pointers crosses the other, at which point we can return our result.

class Solution {
public:

    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        int r = 0, c = 0;

        vector<int> result;

        while (r < m && c < n)
        {
            // Add elements from the top row
            for (int i = c; i < n; ++i)
                result.push_back(matrix[r][i]);
            // increase to next top row
            ++r;

            // Add elements from the last column
            for (int i = r; i < m; ++i)
                result.push_back(matrix[i][n - 1]);
            // Decrease to next last column
            --n;

            // Add elements from the bottom row
            // Check if we still have rows left
            if (r <= m - 1)
            {
                for (int i = n - 1; i >= c; --i)
                    result.push_back(matrix[m - 1][i]);
            }
            // Decrease to next bottom row
            --m;

            // Add elements from the first column
            // Check if we still have columns left
            if (c <= n - 1)
            {
                for (int i = m - 1; i >= r; --i)
                    result.push_back(matrix[i][c]);
            }
            // Increase to next first column
            ++c;
        }

        return result;
    }
};

class OtherSolution {
public:

    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        if (matrix.empty())
            return {};

        int m = matrix.size();
        int n = matrix[0].size();

        int r1 = 0;
        int c1 = 0;
        int r2 = m - 1;
        int c2 = n - 1;

        vector<int> result;

        while (result.size() < m * n)
        {
            for (int j = c1; j <= c2 && result.size() < m * n; ++j)
                result.push_back(matrix[r1][j]);
            for (int i = r1 + 1; i <= r2 && result.size() < m * n; ++i)
                result.push_back(matrix[i][c2]);
            for (int j = c2 - 1; j >= c1 && result.size() < m * n; --j)
                result.push_back(matrix[r2][j]);
            for (int i = r2 - 1; i >= r1 + 1 && result.size() < m * n; --i)
                result.push_back(matrix[i][c1]);
            ++r1, ++c1, --r2, --c2;
        }

        return result;
    }
};