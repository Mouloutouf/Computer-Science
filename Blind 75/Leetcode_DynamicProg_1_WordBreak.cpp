#include <string>
#include <vector>

using namespace std;

// EXPLANATION

// Given a string s and a list of words, return if it is possible to break s into words from the list.
// Ex : string s : "leetcode", list words = "leet", "code", result : true, we can break s into the words from the list.

// The main idea here is to go through s in reverse order, and try to match words progressively.
// If we find a word that matches the section of s at the index we are currently on, then we mark that section (index) with the same value of the section that is after (the previous one).
// That way, if all sections of the word did indeed match a word, then when returning the value of the very first section (index zero), it will be true. Otherwise, it will be false.
// The way we set up this chain reaction is by setting this list of values to have exactly the length of s + 1 values, with that last extra value set to true.
// That way, if we find a match for the last section (the first one we should find), it will set that section to have the same value of the section before, hence it will be true.
// If we then keep finding matches for each subsequent sections, we will eventually end up having the very first section set to true.

class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict)
    {
        // Initialize the list of values to the length of s + 1, then set the last value to true, to set up the chain reaction
        vector<int> dp(s.length() + 1, false);
        dp[s.length()] = true;

        // Go through s in reverse order
        for (int i = s.length() - 1; i >= 0; --i)
        {
            // try to find a match in words
            for (string& word : wordDict)
            {
                // There is a match only if the string is long enough to match the word at that index, and, the word and the section are the same
                if (i + word.length() <= s.length() && s.substr(i, word.length()) == word)
                    dp[i] = dp[i + word.length()];
                // If we have found a right match, we can break since we do not need to look for other words
                // /!\ Note that if we find a match but it does not give us true it means we could not connect to the previous section,
                // it then makes sense for us to continue looking for other matches, otherwise we can continue safely
                if (dp[i] == true)
                    break;
            }
        }
        // Return the value of the first section
        return dp[0];
    }
};