#include <vector>
#include <string>
#include <sstream>

using namespace std;

// EXPLANATION

// Design an algorithm that can encode a list of strings to a single string, and decode that single string back to the original list of strings.

// The challenge here is really to understand how we can encode our strings in a format that can later be read to decode it back.
// The main assumption would be to use a specific character to seperate each word in the encode process, then check for that character when decoding the single string.
// But this will not work since any character can be present in the given strings, so there are no unused character we can safely take for checking.

// The way to solve this is actually through the use of both a specififc character, and a number.
// The way we will encode it is, for every word, we will prefix it with a number that is its size, and then a specific character like '_'.
// That way, when decoding, whenever we encounter the specific character, we can look to the character that is just before, which is the number of letters,
// convert it to an integer, and then use it to retrieve only the next n characters after the specific character, which are guaranteed to be the word we are looking for.
// Then we can just jump to the next prefix, and so on, until we have decoded all of our strings. And since we jump from prefix to prefix, this is guaranteed to work,
// even if the words we encoded were all made up of numbers followed by '_'.

// This runs in O(n) time and in O(n) space

class Solution {
public:

    string encode(vector<string>& strs)
    {
        string encodedStr;

        for (auto& str : strs)
            encodedStr += to_string(str.length()) + "_" + str;

        return encodedStr;
    }

    vector<string> decode(string s)
    {
        vector<string> decodedStrs = vector<string>();

        string numberStr;

        for (int i = 0; i < s.length(); ++i)
        {
            // if we find our specific character
            if (s[i] == '_')
            {
                // convert our number to an integer
                int number;
                stringstream ss;
                ss << numberStr;
                ss >> number;

                // construct a string with the n next characters and add them to our result
                decodedStrs.push_back(s.substr(i + 1, number));

                // clear the current number and jump to the next prefix
                numberStr.clear();
                i += number + 1;
            }
            // store the number of the next prefix
            numberStr.push_back(s[i]);
        }

        return decodedStrs;
    }
};

// Another way to do this

class OtherSolution {
public:

    string encode(vector<string>& strs)
    {
        string result;

        for (auto& str : strs)
            result += to_string(str.length()) + "_" + str;

        return result;
    }

    vector<string> decode(string s)
    {
        vector<string> result = vector<string>();

        int i = 0;
        while (i < s.length())
        {
            int j = i;
            while (s[j] != '_')
                j++;
            
            string nstr = s.substr(i, j - i);
            int n;
            stringstream ss;
            ss << nstr;
            ss >> n;

            result.push_back(s.substr(j + 1, n));

            i = j + n + 1;
        }
        
        return result;
    }
};