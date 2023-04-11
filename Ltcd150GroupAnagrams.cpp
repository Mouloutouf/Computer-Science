#include <string>
#include <vector>
#include <map>

using namespace std;

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