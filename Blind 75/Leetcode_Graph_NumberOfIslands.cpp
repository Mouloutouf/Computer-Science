#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// EXPLANATION

// This is the classic number of islands problem.

// This first solution is good, but better adapted to Python, as it is a bit complex to write in C++

// I do not know how fast in big O this runs

class Solution {
public:

    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& marked, int x, int y, int rows, int columns)
    {
        queue<pair<int, int>> q;

        marked[x][y] = true;
        q.push({x, y});

        while (q.empty() == false)
        {
            pair<int, int> cur = q.front(); // Very important, this is front and not back you need to use, otherwise this will act like a stack
            q.pop();

            pair<int, int> directions[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for (int i = 0; i < 4; ++i)
            {
                x = cur.first;
                y = cur.second;

                int dx = directions[i].first;
                int dy = directions[i].second;

                if (x + dx >= 0 && x + dx < rows && y + dy >= 0 && y + dy < columns &&
                    grid[x + dx][y + dy] == '1' && marked[x + dx][y + dy] == false)
                {
                    marked[x + dx][y + dy] = true;
                    q.push({x + dx, y + dy});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid)
    {
        if (grid.size() == 0)
            return 0;

        int rows = grid.size();
        int columns = grid[0].size();

        vector<vector<bool>> marked(rows, vector<bool>(columns, false));

        int result = 0;

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                if (grid[i][j] == '1' && marked[i][j] == false)
                {
                    bfs(grid, marked, i, j, rows, columns);
                    result++;
                }
            }
        }

        return result;
    }
};

// This is a better solution for C++

// Alternative solution that uses less memory, where we just change the land tiles to water tiles when visited
// Also we use a recursive breadth first search instead of having a queue. This solution is definitely simpler.

class OtherSolution {
public:

    void bfs(vector<vector<char>>& grid, int x, int y)
    {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == '0')
            return;
        
        grid[x][y] = '0';

        bfs(grid, x + 1, y);
        bfs(grid, x - 1, y);
        bfs(grid, x, y + 1);
        bfs(grid, x, y - 1);
    }

    int numIslands(vector<vector<char>>& grid)
    {
        int islands = 0;

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == '1')
                {
                    bfs(grid, i, j);
                    islands++;
                }
            }
        }

        return islands;
    }
};