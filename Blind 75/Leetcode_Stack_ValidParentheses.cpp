#include <vector>
#include <string>
#include <stack>
#include <map>

using namespace std;

// TODO

class Solution {
public:

    bool isValid(string s)
    {
        stack<char> stack;
        map<char, char> parentheses = {{')', '('}, {']', '['}, {'}', '{'}};

        for (char& c : s)
        {
            if (parentheses.count(c) == true)
            {
                if (stack.empty() == false && stack.top() == parentheses[c])
                    stack.pop();
                
                else return false;
            }
            else stack.push(c);
        }

        if (stack.empty() == true)
            return true;
        
        return false;
    }
};