#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1, c = 0; 
        string sum = "";
        while (i >= 0 || j >= 0 || c == 1){
            c += i >= 0 ? a[i--] - '0' : 0;
            c += j >= 0 ? b[j--] - '0' : 0;
            sum = char(c % 2 + '0') + sum;    
            c /= 2;
        }
        return sum;
    }
};