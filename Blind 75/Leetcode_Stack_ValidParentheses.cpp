#include <vector>
#include <string>
#include <stack>
#include <map>

using namespace std;

// EXPLANATION

// This is the classic stack problem of parentheses.

// This is very easy and straightforward, we implement a stack, and add open parentheses inside of it.
// Whenever we encounter a closed parenthese, we try to match it with the top parenthese. if it works, then we remove the top parenthese, otherwise, we return false, it is not valid.
// If by the end, the stack is not empty, then it is not valid, otherwise all parentheses were opened and closed at some point, the string is valid.

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