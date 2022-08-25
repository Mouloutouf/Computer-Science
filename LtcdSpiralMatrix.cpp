#include <vector>

using namespace std;

class Solution {
public:
    void progress(int& x, int& y, int status) {
        switch (status){
            case 1 : ++x; break;
            case 2 : ++y; break;
            case 3 : --x; break;
            case 4 : --y; break;
        }
    }
    bool checkNext(int x, int y, int a, int b, int c, int d, int status) {
        switch (status){
            case 1 : return x + 1 >= b;
            case 2 : return y + 1 >= a;
            case 3 : return x - 1 < d;
            case 4 : return y - 1 < c;
        }
        return false;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int a = m, b = n, c = 0, d = 0;
        int i = 0;
        int x = 0, y = 0;
        int st = 1;
        vector<int> arr;
        while (i < m * n){
            arr.push_back(matrix[y][x]);
            if (checkNext(x, y, a, b, c, d, st)){
                if (st >= 4){
                    st = 1;
                }
                else{
                    ++st;
                }
                if (st == 4){
                    --a;
                    --b;
                    ++c;
                    ++d;
                }
            }
            progress(x, y, st);
            ++i;
        }
        return arr;
    }
};

class OtherSolution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int r = 0, c = 0;
        vector<int> arr;
        while (r < m && c < n)
        {
            // first row
            for (int i = c; i < n; ++i){
                arr.push_back(matrix[r][i]);
            }
            ++r;
            // last column
            for (int i = r; i < m; ++i){
                arr.push_back(matrix[i][n - 1]);
            }
            --n;
            // last row
            if (r <= m - 1){
                for(int i = n - 1; i >= c; --i){
                    arr.push_back(matrix[m - 1][i]);
                }
            }
            --m;
            // first column
            if (c <= n - 1){
                for(int i = m - 1; i >= r; --i){
                    arr.push_back(matrix[i][c]);
                }
            }
            ++c;
        }
        return arr;
    }
};