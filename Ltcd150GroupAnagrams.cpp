#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

// This solution was a good try, taking from the first anagram exercise and applying it to multiple values, adding them to the list as we go
// and breaking from the anagram check whenever we found a match. But it obviously was not enough, as this might be O(n2) in the worst case scenario.

class Solution
{
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

// This solution is way better since it uses the simpler sort solution of the first anagram exercise. Which makes it more efficient here.
// But here, we actually don't need to compare anagrams to each other, we just need to store them at the right place.
// To do that, we use a dictionary to store the group indexes for each anagram we encounter, which allows us to directly store a word that matches an anagram to the right group
// If the anagram is not registered, then we have found a new one, therefore we create a new group within our result list, and register this group index in our anagram dictionary

class BestSolution
{
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

class VerboseSolution
{
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