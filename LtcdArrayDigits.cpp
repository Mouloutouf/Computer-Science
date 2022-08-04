#include <vector>
using namespace std;

/*
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Input: digits = [9,9]
Output: [1,0,0]
Explanation: The array represents the integer 99.
Incrementing by one gives 99 + 1 = 100.
Thus, the result should be [1,0,0].
*/

// For each digit, starting from the end, check if it is a 9. if it is, set it to 0 and continue to the next digit.
// If the index goes to -1, we have reached further than our array (all digits were 9), therefore add a zero at the end, and set the index at 0.
// Then increase the current digit by one.
// Return the digits.

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= -1; --i){
            if (i == -1){
                digits.push_back(0);
                i = 0;
            }
            if (digits[i] == 9){
                digits[i] = 0;
                continue;
            }
            digits[i]++;
            break;
        }
        return digits;
    }
};