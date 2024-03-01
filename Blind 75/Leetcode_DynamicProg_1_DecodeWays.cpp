#include <string>
#include <vector>
#include <map>

using namespace std;

// TODO IMPORTANT

// /!\ I don't completely understand this solution, i don't think it works in C++ also

class Solution {
public:

    int decodeSearch(string& s, map<int, int>& decodings, int i)
    {
        if (decodings.count(i))
            return decodings[i];
        
        if (s[i] == '0')
            return 0;
        
        int result = decodeSearch(s, decodings, i + 1);

        if (i + 1 < s.length())
        {
            int first = s[i] - '0';
            int second = s[i + 1] - '0';

            if (first == 1 || (first == 2 && second >= 0 && second <= 6))
                result += decodeSearch(s, decodings, i + 2);
        }
        decodings[i] = result;

        return result;
    }

    int numDecodings(string s)
    {
        map<int, int> decodings;

        return decodeSearch(s, decodings, 0);
    }
};

// TODO ANALYSIS

// This is not my code

class Solution {
public:

    int numDecodings(string s)
    {
        if (s.empty() || s[0] == '0')
            return 0;

        int n = s.length();

        vector<int> dp(n + 1, 0);

        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i)
        {
            int oneDigit = s[i - 1] - '0';
            int twoDigits = stoi(s.substr(i - 2, 2));

            if (oneDigit != 0)
                dp[i] += dp[i - 1];

            if (10 <= twoDigits && twoDigits <= 26)
                dp[i] += dp[i - 2];
        }

        return dp[n];
    }
};