#include <string>

using namespace std;

// EXPLANATION

// Given a string s, return the longest possible palindromic substring in s.

// The solution to this problem is to go through all the characters in the string, and check if a palindrome exist, starting at each character, then expanding in both directions.
// This works since a palindrome is symetrical, hence we can easily check the longest possible palindrome for each character.
// In order to do this, we need to have two pointers, one left and one right, and progress them in opposite directions, while checking that they have the exact same value.
// While this is true, we are going to keep progressing these pointers, and registering the palindrome as it gets bigger, if and only if, it is larger than the current longest palindrome
// That way, we end up finding the longest palindromic substring.
// One important thing though, we need to run this palindromic check algorithm twice, one time for odd palindromes, with both pointers starting at the same value,
// and one time for even palindromes, with the left pointer starting at the current value, and the right pointer starting at the next value.
// That way, we are sure to check all possible palindromes.

// I do not know how fast in big O this runs

class Solution {
public:

    string longestPalindrome(string s)
    {
        string result = "";
        int length = 0;

        for (int i = 0; i < s.length(); ++i)
        {
            // odd palindrome, start both pointers at same value
            int l = i, r = i;
            while (l >= 0 && r < s.length() && s[l] == s[r])
            {
                if ((r - l + 1) > length)
                {
                    length = (r - l + 1);
                    result = s.substr(l, length);
                }
                l--;
                r++;
            }

            // even palindrome, start left pointer at value and right pointer at next value
            l = i, r = i + 1;
            while (l >= 0 && r < s.length() && s[l] == s[r])
            {
                if ((r - l + 1) > length)
                {
                    length = (r - l + 1);
                    result = s.substr(l, length);
                }
                l--;
                r++;
            }
        }
        return result;
    }
};