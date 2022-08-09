#include <string>
#include <map>
using namespace std;

// Shit Solution
// Slow and Too Much Memory
// I'm a Dumb Ass, There is Much Simpler

class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> c;
        for (int i = 0; i < s.size(); ++i){
            if (c.count(s[i]) != 0){
                c[s[i]] = -1;
            }
            else{
                c[s[i]] = i;
            }
        }
        int a = -1;
        for (auto &ch : c){
            if (ch.second != -1){
                if (a == -1 || ch.second < a){
                    a = ch.second;
                }
            }
        }
        return a;
    }
};

// Simpler Solution
// Still too Slow since Map is Slow (apparently) and Leetcode Runtime is Still Complete Shit

class SimpleSolution {
public:
    int firstUniqChar(string s) {
        map<char, int> c;
        for (int i = 0; i < s.length(); ++i){
            c[s[i]]++;
        }
        for (int i = 0; i < s.length(); ++i){
            if (c[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};

// Same Solution but uses an Array instead of a Map
// Faster and uses Less Memory

class BetterSolution {
public:
    int firstUniqChar(string s) {
        int a[26] = {0};
        for (int i = 0; i < s.length(); ++i){
            a[s[i] - 'a']++;
        }
        for (int i = 0; i < s.length(); ++i){
            if (a[s[i] - 'a'] == 1){
                return i;
            }
        }
        return -1;
    }
};