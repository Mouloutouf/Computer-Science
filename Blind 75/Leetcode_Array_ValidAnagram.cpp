#include <string>
#include <algorithm>
#include <map>

using namespace std;

// Given two strings a and b, find if they are the anagram of one another (meaning they have the exact same letters).

// This is the best solution, runs in O(n) with memory O(26)

// The solution here is first to check if both strings have the same length. if they are different, then we do not have an anagram.
// Then we just go through both strings at the same time, registering every character in an array (which represents a map of all 26 letters of the alphabet in our case)
// we then increase the counter for the corresponding letter for the first string, and decrease the counter for the second string.
// After that, we just go through our 26 letters, and check if any value is different than 0. If all values are at 0, then we do have an anagram.
// since all letters from both words canceled each other.

class Solution
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

class EasySolution
{
public:
    bool isAnagram(string s, string t)
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

// This solution is obviously slower but is more universal as it will work with any unicode alphabet no matter the culture
// whereas the first solution only works in the context of having only lowercase latin characters

class UniversalSolution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        
        map<char, int> elements;

        for (int i = 0; i < s.length(); ++i)
        {
            elements[s[i]]++;
            elements[t[i]]--;
        }

        for (auto& pair : elements)
        {
            if (pair.second != 0)
                return false;
        }
        return true;
    }
};