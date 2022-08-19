#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

// Given different Words, Determine the Number of Unique Morse Codes from these Words
// What we do here is, for each Word we have, we first convert it to a Morse Code, then Add it to a Hash Set (a Container of Unique Values)
// We then return the Hash Set Size, which will contain every Unique Generated Morse Codes

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string alphabet[] = {".-","-...","-.-.","-..",".","..-.","--.",
                             "....","..",".---","-.-",".-..","--","-.",
                             "---",".--.","--.-",".-.","...","-","..-",
                             "...-",".--","-..-","-.--","--.."};
        unordered_set<string> morses;
        for (string& word : words){
            string morse = "";
            for (char& letter : word){
                morse += alphabet[letter - 'a'];
            }
            morses.insert(morse);
        }
        return morses.size();
    }
};