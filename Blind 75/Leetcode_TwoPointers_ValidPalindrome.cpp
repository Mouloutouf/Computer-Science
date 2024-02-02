#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    bool isPalindrome(string s)
    {
        string newStr;
        string reverseStr;

        for (int i = 0; i < s.length(); ++i)
        {
            if (isalnum(s[i]))
                newStr.push_back(tolower(s[i]));
        }
        reverseStr = newStr;
        reverse(reverseStr.begin(), reverseStr.end());

        return newStr == reverseStr;
    }
};

class BestSolution {
public:

    bool isPalindrome(string s)
    {
        int i = 0;
        int j = s.length() - 1;

        while (i < j)
        {
            while (isalnum(s[i]) == false)
            {
                if (i >= s.length())
                    return true;
                i++;
            }
            
            while (j >= 0 && isalnum(s[j]) == false)
            {
                if (j < 0)
                    return true;
                j--;
            }

            if (tolower(s[i]) != tolower(s[j]))
                return false;
            
            i++;
            j--;
        }
        return true;
    }
};