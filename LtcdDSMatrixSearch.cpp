#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        map<int, int> indexes;
        int i = (m * n) / 2;
        int c = i;
        while (true){
            if (indexes[i] > 0){
                break;
            }
            indexes[i]++;
            int a = (i / n);
            int b = (i % n);
            c = (c / 2) + (c % 2);
            if (matrix[a][b] > target){
                i -= c;
                if (i < 0){
                    i = 0;
                }
            }
            else if (matrix[a][b] < target){
                i += c;
                if (i >= m * n){
                    i = (m * n) - 1;
                }
            }
            else{
                return true;
            }
        }
        return false;
    }
};

class OtherSolution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int start = 0, end = (n * m) - 1;
        int c = 0;
        int i = 0, j = 0;
        while(start <= end) {
            c = (start + end) / 2;
            i = c / n;
            j = c % n;
            if (matrix[i][j] < target){
                start = c + 1;
            }
            else if (matrix[i][j] > target){
                end = c - 1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
