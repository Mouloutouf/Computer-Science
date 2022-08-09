#include <string>
#include <algorithm>
using namespace std;

// Both of the Two First Solutions have Good Runtime and Good Memory

class Solution {
public:
    bool isAnagram(string s, string t) {
        int a[26] = {0};
        int b[26] = {0};
        for (int j = 0; j < s.length(); ++j){
            a[s[j] - 'a']++;
        }
        for (int k = 0; k < t.length(); ++k){
            b[t[k] - 'a']++;
        }
        for (int i = 0; i < 26; ++i){
            if (a[i] != b[i]){
                return false;
            }
        }
        return true;
    }
};

// This has Slightly Better Runtime

class OtherSolution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()){
            return false;
        }
        int a[26] = {0};
        int b[26] = {0};
        for (int j = 0; j < s.length(); ++j){
            a[s[j] - 'a']++;
            b[t[j] - 'a']++;
        }
        for (int i = 0; i < 26; ++i){
            if (a[i] != b[i]){
                return false;
            }
        }
        return true;
    }
};

// This is Better than all Others
// Beats Runtime and Memory
// Only One Array of Data, only Two Loops, with a Safe Check to Limit Calculations

class BestSolution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()){
            return false;
        }
        int a[26] = {0};
        for (int i = 0; i < s.length(); ++i){
            a[s[i] - 'a']++;
            a[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; ++i){
            if (a[i] != 0){
                return false;
            }
        }
        return true;
    }
};

// This has Better Memory
// But Way Worst Runtime

class CheatSolution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};