#include <string>
#include <algorithm>
using namespace std;

// Given two strings a and b, find if they are the anagram of one another (meaning they have the exact same letters).

// The first solution has good runtime O(n) and good memory O(52).
// Explanation for this below, here we use two arrays for the alphabet, which is overkill since we can only use one.

class FirstSolution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        int a[26] = {0};
        int b[26] = {0};
        for (int j = 0; j < s.length(); ++j)
        {
            a[s[j] - 'a']++;
            b[t[j] - 'a']++;
        }
        for (int i = 0; i < 26; ++i)
        {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }
};

// This is better than the previous one, runs in O(n) with memory O(26)

// The solution here is first to check if both strings have the same length. if they are different, then we do not have an anagram.
// Then we just go through both strings at the same time, registering every character in an array (which represents a map of all 26 letters of the alphabet in our case)
// we then increase the counter for the corresponding letter for the first string, and decrease the counter for the second string.
// After that, we just go through our 26 letters, and check if any value is different than 0. If all values are at 0, then we do have an anagram.
// since all letters from both words canceled each other.

class BestSolution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        int a[26] = {0};
        for (int i = 0; i < s.length(); ++i)
        {
            a[s[i] - 'a']++;
            a[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; ++i)
        {
            if (a[i] != 0)
                return false;
        }
        return true;
    }
};

// This has better memory O(1) but way worst runtime
// Obviously here its pretty easy, we just sort them both then see if they come out the same.

class CheatSolution
{
public:
    bool isAnagram(string s, string t)
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};