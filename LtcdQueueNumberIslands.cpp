#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), columns = grid[0].size();
        // initialize breadth first search data structures
        queue<int> rowSearch, columnSearch;
        vector<vector<bool>> visited = vector<vector<bool>>(rows, vector<bool>(columns));
        // utility arrays for neighbour search
        int rowDirs[4] = {-1, 1, 0, 0}, columnDirs[4] = {0, 0, 1, -1};
        // islands count
        int islands = 0;
        // search the entire grid
        for (int i = 0; i < grid.size(); ++i){
            for (int j = 0; j < grid[i].size(); ++j){
                // already visited land tile or water tile, continue
                if (visited[i][j] == true || grid[i][j] == '0'){
                    continue;
                }
                // unvisited land tile, explore the whole island
                // add the land tile to the search queues
                // mark the land tile as visited
                rowSearch.push(i);
                columnSearch.push(j);
                visited[i][j] = true;
                // explore the island using breadth first search
                while (rowSearch.size() > 0){
                    // select a land tile from the search queues
                    int a = rowSearch.front(), b = columnSearch.front();
                    rowSearch.pop();
                    columnSearch.pop();
                    // search the neighbours of the current land tile
                    for (int n = 0; n < 4; ++n){
                        int na = a + rowDirs[n], nb = b + columnDirs[n];
                        // out of bounds, continue
                        if (na < 0 || nb < 0 || na >= rows || nb >= columns){
                            continue;
                        }
                        // already visited land tile or water tile, continue
                        if (visited[na][nb] == true || grid[na][nb] == '0'){
                            continue;
                        }
                        // add it to the search queues
                        // mark it as visited
                        rowSearch.push(na);
                        columnSearch.push(nb);
                        visited[na][nb] = true;
                    }
                }
                // island searched add it to the count
                islands++;
                // empty the search queues
                rowSearch = queue<int>();
                columnSearch = queue<int>();
            }
        }
        return islands;
    }
};

// Loop through the grid until a land tile is found then depth first search the whole island from that tile and replace all land tiles with water tiles

class BetterSolution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for (int i = 0; i < grid.size(); ++i){
            for (int j = 0; j < grid[0].size(); ++j){
                if (grid[i][j] == '1'){
                    dfs(grid, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }
    void dfs(vector<vector<char>>& grid, int x, int y) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == '0')
            return;
        grid[x][y] = '0';
        dfs(grid, x + 1, y);
        dfs(grid, x - 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x, y - 1);
    }
};

// Same solution but with grid sizes passed through the method and visited tiles marked with a new index

class VariantSolution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int rows = grid.size(), columns = grid[0].size();
        for (int i = 0; i < grid.size(); ++i){
            for (int j = 0; j < grid[0].size(); ++j){
                if (grid[i][j] == '1'){
                    dfs(grid, rows, columns, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }
    void dfs(vector<vector<char>>& grid, int rows, int columns, int x, int y) {
        if (x < 0 || y < 0 || x >= rows || y >= columns || grid[x][y] != '1')
            return;
        grid[x][y] = '2';
        dfs(grid, rows, columns, x + 1, y);
        dfs(grid, rows, columns, x - 1, y);
        dfs(grid, rows, columns, x, y + 1);
        dfs(grid, rows, columns, x, y - 1);
    }
};