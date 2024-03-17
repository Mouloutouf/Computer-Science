#include <vector>
using namespace std;

// TODO

class Solution {
public:

    void rotate(vector<vector<int>>& matrix)
    {
        int n = matrix.size();

        for (int step = 0; step < n; ++step)
        {
            for (int element = n - 1; element >= 0; --element)
            {
                matrix[step].push_back(matrix[element][step]);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            matrix[i].erase(matrix[i].begin(), matrix[i].end() - n);
        }
    }
};

class OtherSolution {
public:

    void rotate(vector<vector<int>>& matrix)
    {
        int n = matrix.size();

        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};