#include <vector>
#include <queue>

using namespace std;

// TODO

class Solution {
public:

    void dfs(vector<vector<int>>& heights, int x, int y, vector<vector<bool>>& ocean, int prev, int rows, int cols)
    {
        if (x < 0 || x >= rows || y < 0 || y >= cols ||
            ocean[x][y] == true || heights[x][y] < prev)
            return;
        
        ocean[x][y] = true;

        dfs(heights, x + 1, y, ocean, heights[x][y], rows, cols);
        dfs(heights, x - 1, y, ocean, heights[x][y], rows, cols);
        dfs(heights, x, y + 1, ocean, heights[x][y], rows, cols);
        dfs(heights, x, y - 1, ocean, heights[x][y], rows, cols);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pacific(vector<vector<bool>>(rows, vector<bool>(cols, false)));
        vector<vector<bool>> atlantic(vector<vector<bool>>(rows, vector<bool>(cols, false)));

        for (int j = 0; j < cols; ++j)
        {
            dfs(heights, 0, j, pacific, heights[0][j], rows, cols);
            dfs(heights, rows - 1, j, atlantic, heights[rows - 1][j], rows, cols);
        }
        for (int i = 0; i < rows; ++i)
        {
            dfs(heights, i, 0, pacific, heights[i][0], rows, cols);
            dfs(heights, i, cols - 1, atlantic, heights[i][cols - 1], rows, cols);
        }

        vector<vector<int>> result = vector<vector<int>>();

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (pacific[i][j] == true && atlantic[i][j] == true)
                    result.push_back(vector<int>({i, j}));
            }
        }

        return result;
    }
};