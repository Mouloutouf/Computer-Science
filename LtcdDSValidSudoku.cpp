#include <vector>
#include <map>
using namespace std;

// Given a Sudoku Board with Partially Filled Cells, Determine if it is Valid (Determine if there are Repetitions or Not).
// The Solution for this is to go through the Board Three Times, Each Time Checking for a Specific Array. First Rows, Then Columns, and Lastly Squares
// What we then Do is we Add the Numbers we Find inside a Map and Keep Track of how Many Times we Encounter Them.
// If we Encounter Them More than Once, the Board is not Valid, there is a Repetition in the Specified Array.
// After Each Array, we Clear the Map, and Continue onto the Next One.
// For the Squares, we also had to Calculate the Indexes to Access this Specific Array in the Board, which we Do with a Special Calculation.

// Note
// Leetcode Runtime Reports are Absolutely Inconsistent and Complete Shit
// Therefore Any of the Solutions Here have Best Runtime

// Okay Solution
// Runtime and Memory is Okay

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<char, int> occurences;
        for (int i = 0; i < 9; ++i){
            for (int j = 0; j < 9; ++j){
                if (board[i][j] != '.'){
                    occurences[board[i][j]]++;
                }
                if (occurences[board[i][j]] > 1){
                    return false;
                }
            }
            occurences.clear();
        }
        for (int i = 0; i < 9; ++i){
            for (int j = 0; j < 9; ++j){
                if (board[j][i] != '.'){
                    occurences[board[j][i]]++;
                }
                if (occurences[board[j][i]] > 1){
                    return false;
                }
            }
            occurences.clear();
        }
        for (int i = 0; i < 9; ++i){
            for (int j = 0; j < 9; ++j){
                int a = (j / 3) + 3 * (i / 3);
                int b = (j % 3) + 3 * (i % 3);
                if (board[a][b] != '.'){
                    occurences[board[a][b]]++;
                }
                if (occurences[board[a][b]] > 1){
                    return false;
                }
            }
            occurences.clear();
        }
        return true;
    }
};

// Insane Solution
// Runtime is Okay but Memory is Best

class OtherSolution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int subBoard[9] = {0};
        int colBoard[9] = {0};
        int rowBoard[9] = {0};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.'){
                    continue;
                }
                // Convert Char to Int
                int val = board[i][j] - '0';
                int pos = 1 << (val - 1);
                // Rows Check
                if ((rowBoard[i] & pos) > 0){
                    return false;
                }
                else{
                    rowBoard[i] |= pos;
                }
                // Columns Check
                if ((colBoard[j] & pos) > 0){
                    return false;
                }
                else{
                    colBoard[j] |= pos;
                }
                // Squares Check
                int k = (i / 3) * 3 + (j / 3);
                if ((subBoard[k] & pos) > 0){
                    return false;
                }
                else{
                    subBoard[k] |= pos;
                }
            }
        }
        return true;
    }
};

// Great Solution and Best Solution
// Runtime and Memory is Best

class AnotherSolution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int subBoard[3][3][9] = {0};
        int colBoard[9][9] = {0};
        int rowBoard[9][9] = {0};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.'){
                    continue;
                }
                int val = board[i][j] - '1';
                if (subBoard[i / 3][j / 3][val] > 0 || colBoard[j][val] > 0 || rowBoard[i][val] > 0){
                    return false;
                }
                subBoard[i / 3][j / 3][val] = 1;
                colBoard[j][val] = 1;
                rowBoard[i][val] = 1;
            }
        }
        return true;
    }
};

// Fucked Up Solution
// This Runs Faster than All Other Solutions and with Best Memory Usage
// I can't believe this shit.
// This is literally just nested for loops all over. Exactly what I tried not doing. What the actual fuck.

class FuckedSolution {
public:
    bool isValid(int a, int b, vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (i != b && board[a][i] == board[a][b]){
                return false;
            }
        }
        for (int i = 0; i < 9; i++) {
            if (i != a && board[i][b] == board[a][b]){
                return false;
            }
        }
        int x = a / 3 * 3;
        int y = b / 3 * 3;
        int c = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[x + i][y + j] == board[a][b]){
                    c++; 
                }
            } 
        }
        return c == 1;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (isValid(i, j, board) == false){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};