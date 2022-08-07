#include <vector>
using namespace std;

// Given a Matrix of size m * n, reshape that matrix to a new size r * c, if it is possible.
// Both Solutions are valid.
// First, in both solutions, we check to see if the size of our matrix is equal to the size of the potential reshaped matrix, to know if we can reshape our elements.
// If it's not, we return, we cannot reshape the matrix.
// Otherwise there are two ways of doing this.
// First Solution :
// Create a one-dimensional array, and store the elements of the first matrix in it. Then reshape the matrix. Then put back all the elements in the matrix.
// Second Solution :
// Create a new two-dimensional reshaped matrix, and loop through the first matrix to put its elements in the new one.

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if (r * c != m * n){
            return mat;
        }
        vector<int> arr(r * c);
        int k = 0;
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                arr[k] = mat[i][j];
                ++k;
            }
        }
        mat = vector<vector<int>>(r, vector<int>(c));
        k = 0;
        for (int a = 0; a < r; ++a){
            for (int b = 0; b < c; ++b){
                mat[a][b] = arr[k];
                ++k;
            }
        }
        return mat;
    }
};

class OtherSolution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if (r * c != m * n){
            return mat;
        }
        vector<vector<int>> res(r, vector<int>(c));
        int x = 0, y = 0;
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (y == c){
                    ++x;
                    y = 0;
                }
                res[x][y] = mat[i][j];
                ++y;
            }
        }
        return res;
    }
};