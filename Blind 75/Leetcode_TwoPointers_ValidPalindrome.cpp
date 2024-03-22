#include <vector>
#include <string>

using namespace std;

// EXPLANATION

// Given a string s, return whether the string is a palindrome.
// You should ignore any non alphanumeric characters including spaces, and consider all letters to be lowercase. This means we really check if the lowercase connected string is a palindrome.
// An empty string is also a palindrome.

// The solution here is quite straightforward, we should use two pointers to go through the word from the left and the right at the same time, and check for discrepancies.
// if both pointers end up crossing each other, then both parts of the word have been verified and are indeed equivalent, thus the word is a palindrome.
// But since we need to ignore non relevant characters, we need to check whether the current character is alphanumerical, and if it isn't then we have to skip it, so progress the current pointer.
// Whenever both our pointers point to an alphanumerical value, compare their lowercase representation, if they match then continue, otherwise, the word is not a palindrome.

// There is however one thing that is important to add when implementing this solution, since Leetcode are a bunch of cock suckers, and otherwise you won't pass all test cases.
// You need to make sure you don't cross the ends of the string when you skip values. Because if the string is only made up of irrelevant characters, then you will increment your pointer
// indefinitely, until you find yourself out of range. So you should check and return true if that happens, since that means we have an empty palindrome.

// This runs in O(n) time and in O(1) space

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
                i++;

                // Check for edge case empty palindrome
                if (i >= s.length())
                    return true;
            }
            
            while (isalnum(s[j]) == false)
                j--;

            if (tolower(s[i]) != tolower(s[j]))
                return false;
            
            i++;
            j--;
        }
        return true;
    }
};