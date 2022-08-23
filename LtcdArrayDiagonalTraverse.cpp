#include <vector>

using namespace std;

// Given a 2D Array, return an Array of its Elements in Diagonal Order
// Here, Diagonal Order means we need to traverse the 2D Array in a Zig Zag Pattern
// For a 3x3 Array, Go from [0,0] to [0,1] to [1,0] to [2,0] to [1,1] to [0,2] to [1,2] to [2,1] to [2,2]
// What we can see here is that if you sum them up you get : 0, 1, 1, 2, 2, 2, 3, 3, 4. Where Each Unique Value represents a Diagonal
// That way, the Solution is just to store each Diagonal in a Map
// Then put them back into a normal Array. But in order to have this Zig Zag Pattern, we will have to add the Elements either from
// the Start or from the End. So we just check if the diagonal is pair or not to know how to traverse it.
// Then we return our array

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> map(m + n, vector<int>());
        vector<int> arr;
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                map[i + j].push_back(mat[i][j]);
            }
        }
        for (int k = 0; k < map.size(); ++k){
            if (k % 2 == 0){
                for (int y = map[k].size() - 1; y >= 0; --y){
                    arr.push_back(map[k][y]);
                }
            }
            else{
                for (int x = 0; x < map[k].size(); ++x){
                    arr.push_back(map[k][x]);
                }
            }
        }
        return arr;
    }
};

// Better Memory Solution but Worse Runtime where we traverse directly the original Array
// the m + n - 1 equals to the number of diagonals in the array. For a 3x3 2D Array, there will be 5 diagonals
// We loop through each Diagonal, but then loop through as many times as the Diagonal 'size' which here is its index.
// Obviously, up until we reach the largest Diagonal in the Array this will work fine, but when we get past it, the Diagonal size will start to shrink
// Therefore we need to check if the values we get are outside the bounds of the array or not. This will create more computation time, as we loop through
// bigger and bigger diagonals and have to ignore more and more outstanding values.
// The x = j and y = i - x, allow us to determine the index of the value in the diagonal
// Then we need to check if we are on an even or odd diagonal, for the Zig Zag, and in an even case, swap the x and y values, to add the elements in the order we want
// After we added all the Elements to the final Array we can return it.

class OtherSolution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> arr;
        for (int i = 0; i < m + n - 1; ++i){
            for (int j = 0; j <= i; ++j){
                int x = j;
                int y = i - x;
                if (i % 2 == 0){
                    swap(x, y);
                }
                if (x >= m || y >= n){
                    continue;
                }
                arr.push_back(mat[x][y]);
            }
        }
        return arr;
    }
};

// Same as Above where we go through the Original Array, but without the Loss in Runtime since we don't go through outstanding values
// For positive values (i & 1 == 0) == (i % 2 != 0). For negative values, (i % 2) won't work, but (i & 1) will.

class BestSolution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> arr (m * n, 0);
        int k = 0;
        for (int i = 0; i < m + n - 1; ++i){
            if ((i & 1) == 0){
                int x = min(i, m - 1);
                int y = max(0, i - m + 1);
                do{
                    arr[k] = mat[x][y];
                    x--;
                    y++;
                    k++;
                }
                while (x >= 0 && y < n);
            }
            else{
                int y = min(i, n - 1);
                int x = max(0, i - n + 1);
                do{
                    arr[k] = mat[x][y];
                    x++;
                    y--;
                    k++;
                }
                while (x < m && y >= 0);
            }
        }
        return arr;
    }
};