#include <string>
using namespace std;

// Good Solution
// As Always, Runtime is Absolutely Fucked on Leetcode
// This is Good Runtime, Very Good Memory

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int a[26] = {0};
        for (int i = 0; i < magazine.length(); ++i){
            a[magazine[i] - 'a']++;
        }
        for (int i = 0; i < ransomNote.length(); ++i){
            if (a[ransomNote[i] - 'a'] == 0){
                return false;
            }
            a[ransomNote[i] - 'a']--;
        }
        return true;
    }
};