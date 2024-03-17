#include <vector>
#include <string>
#include <set>

using namespace std;

// This works but is extremely slow and memory inefficient

class Solution {
public:

    int lengthOfLongestSubstring(string s)
    {
        set<char> letters;

        int maxLength = 0;
        int length = 0;

        int k = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (letters.count(s[i]) == true)
            {
                length = 0;
                letters.clear();

                k++;
                i = k;
            }

            length++;
            letters.emplace(s[i]);

            if (length > maxLength)
                maxLength = length;
        }

        return maxLength;
    }
};

// TODO

// Better solution using a sliding window

class BestSolution {
public:

    int lengthOfLongestSubstring(string s)
    {
        set<char> letters;

        int maxLength = 0;
        int length = 0;

        int j = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            while (letters.count(s[i]) == true)
            {
                letters.erase(s[j]);
                j++;

                length--;
            }

            length++;
            letters.emplace(s[i]);

            if (length > maxLength)
                maxLength = length;
        }

        return maxLength;
    }
};