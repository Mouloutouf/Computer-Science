#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

// EXPLANATION

// Given an array of strings, group the anagrams together.

// The idea here is to go through the given strings, and match them to the correct group in the answer array.
// The answer is represented by an array of arrays, so an array of groups essentially.
// The way we will assign them to the correct groups is using a map, in which we will match the sorted version of a certain string (the letters of the anagram really), to an index,
// which represents the group index in the answer array. This works since all anagrams when sorted give the same string (they have the exact same letters).
// The protocol for this is simple : for every string, store a reference of it as a word, then make a copy and sort that copy, then check if that sorted copy already exist in the map,
// if it does, retrieve the corresponding index and store the word in the answer array. If it does not then create a new group in the answer array, store the word,
// then assign the index of that new group to the map with the sorted copy as key.
// Do this until all strings are matched within a group, then return the answer.

class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        if (strs.size() == 0)
            return {{}};

        vector<vector<string>> result = vector<vector<string>>();
        unordered_map<string, int> groupIndexes;

        for (int i = 0; i < strs.size(); ++i)
        {
            string& word = strs[i];

            string anagram = strs[i];
            sort(anagram.begin(), anagram.end());

            if (groupIndexes.count(anagram) == false)
            {
                result.push_back({word});
                groupIndexes[anagram] = result.size() - 1;
            }
            else
                result[groupIndexes[anagram]].push_back(word);
        }
        return result;
    }
};

class ExplainedSolution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        if (strs.size() <= 0)
            return {{}};

        // stores all values by groups of anagrams
        vector<vector<string>> result;
        // stores all anagrams with their group index
        unordered_map<string, int> anagrams;

        for (int i = 0; i < strs.size(); ++i)
        {
            // take the value and sort it -> turn into anagram so to speak
            string str = strs[i];
            sort(str.begin(), str.end());

            // if anagram is already present in the anagrams dictionary
            if (anagrams.count(str))
            {
                // then add the value in the result list within the group given by anagram
                result[anagrams[str]].push_back(strs[i]);
            }
            // otherwise this is a new anagram / new value
            else
            {
                // add a new group to the result list and put the value in it
                result.push_back({strs[i]});
                // register the anagram in anagrams with the index of the newly created group
                anagrams[str] = result.size() - 1;
            }
        }

        return result;
    }
};

class VerboseSolution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& words)
    {
        if (words.size() <= 0)
            return {{}};

        vector<vector<string>> groups;
        unordered_map<string, int> anagramGroupIndexes;

        for (int i = 0; i < words.size(); ++i)
        {
            string& word = words[i];

            string anagram = words[i];
            sort(anagram.begin(), anagram.end());

            if (anagramGroupIndexes.count(anagram))
            {
                int groupIndex = anagramGroupIndexes[anagram];
                groups[groupIndex].push_back(word);
            }
            else
            {
                groups.push_back({word});

                int newGroupIndex = groups.size() - 1;
                anagramGroupIndexes[anagram] = newGroupIndex;
            }
        }

        return groups;
    }
};

// This solution was a good try, taking from the first anagram exercise and applying it to multiple values, adding them to the list as we go
// and breaking from the anagram check whenever we found a match. But it obviously was not enough, as this might be O(n2) in the worst case scenario.

class ComplicatedSolution {
public:

    bool checkAnagrams(string& s, vector<vector<string>>& anagrams)
    {
        for (int j = 0; j < anagrams.size(); ++j)
        {
            for (auto& t : anagrams[j])
            {
                // if lengths are different, then not anagrams
                if (s.length() != t.length())
                    continue; // no match
                
                // initialize alphabet
                int a[26] = {0};

                // add count for letters in s and t
                for (int i = 0; i < s.length(); ++i)
                {
                    a[s[i] - 'a']++;
                    a[t[i] - 'a']--;
                }

                // check if s and t are anagrams of each other
                bool match = true;
                for (int i = 0; i < 26; ++i)
                {
                    // if one letter differs between them, then not anagrams
                    if (a[i] != 0)
                    {
                        match = false;
                        break;
                    }
                }
                if (match == false)
                    continue; // no match
                
                // as soon as we have a match, store it then return true
                anagrams[j].push_back(s);
                return true;
            }
        }
        // no matches found, return false
        return false;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        if (strs.size() < 1)
            return {{}};
        
        if (strs.size() < 2)
            return {{strs[0]}};

        vector<vector<string>> anagrams;

        // go through all strings
        for (int i = 0; i < strs.size(); ++i)
        {
            string& s = strs[i];

            // check if there is already a match for s, and store it in the same group if so
            if (checkAnagrams(s, anagrams) == true)
                continue;

            // otherwise add a new group to store s
            anagrams.push_back(vector<string>(1, s));
        }

        return anagrams;
    }
};