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
                    int a = rowSearch.back(), b = columnSearch.back();
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