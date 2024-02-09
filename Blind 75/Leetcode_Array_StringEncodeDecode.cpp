#include <vector>
#include <string>
#include <sstream>

using namespace std;

// TODO

// This solution does not work

class Solution {
public:

    string encode(vector<string>& strs)
    {
        string encodedStr;

        for (auto& str : strs)
        {
            encodedStr.append(str);
            encodedStr.push_back('_');
        }

        return encodedStr;
    }

    vector<string> decode(string s)
    {
        vector<string> decodedStrs = vector<string>();

        int begin = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '_' || i == s.length() - 1)
            {
                decodedStrs.push_back(s.substr(begin, i - begin));
                begin = i + 1;
            }
        }

        return decodedStrs;
    }
};

// This is the correct solution

class BestSolution {
public:

    string encode(vector<string>& strs)
    {
        string encodedStr;

        for (auto& str : strs)
            encodedStr += to_string(str.length()) + "_" + str;

        return encodedStr;
    }

    vector<string> decode(string s)
    {
        vector<string> decodedStrs = vector<string>();

        string numberStr;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '_')
            {
                int number;
                stringstream ss;
                ss << numberStr;
                ss >> number;

                decodedStrs.push_back(s.substr(i + 1, number));

                numberStr.clear();
                i += number + 1;
            }

            numberStr.push_back(s[i]);
        }

        return decodedStrs;
    }
};

// Another way to do this

class OtherBestSolution {
public:

    string encode(vector<string>& strs)
    {
        string result;

        for (auto& str : strs)
            result += to_string(str.length()) + "_" + str;

        return result;
    }

    vector<string> decode(string s)
    {
        vector<string> result = vector<string>();

        int i = 0;
        while (i < s.length())
        {
            int j = i;
            while (s[j] != '_')
                j++;
            
            string nstr = s.substr(i, j - i);
            int n;
            stringstream ss;
            ss << nstr;
            ss >> n;

            result.push_back(s.substr(j + 1, n));

            i = j + n + 1;
        }
        
        return result;
    }
};