
#include <stack>
#include <map>
#include <string>

using namespace std;

// Old Solution does not work

class Solution {
public:
    bool isValid(string s) {
        string open = "({[", closed = ")}]";
        // Second Implem
        stack<char> c;
        for (int j = 0; j < s.length(); ++j){

        }
        // First Implem
        stack<char> st;
        st.push(s[0]);
        for (int i = 1; i < s.length(); ++i){
            st.push(s[i]);
            for (int k = 0; k < open.length(); ++k){
                if (s[i - 1] == open[k] && s[i] == closed[k]){
                    st.pop();
                    st.pop();
                }
            }
        }
    }
};

class ActualSolution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char, char> p = {{')', '('}, {']', '['}, {'}', '{'}};
        for (char& c : s){
            // if the char is a closing brace
            if (p.count(c)){
                // check if the last element in the stack is the corresponding open brace
                // if it is remove it from the stack and continue
                if (st.empty() == false && st.top() == p[c]){
                    st.pop();
                }
                // if it is not then the string is not valid
                else{
                    return false;
                }
            }
            // if the char is an open brace add it to the stack
            else{
                st.push(c);
            }
        }
        // at the end if the stack is empty then all braces were open and closed
        // the string is therefore valid
        if (st.empty()){
            return true;
        }
        // otherwise it is not
        return false;
    }
};