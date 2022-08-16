#include <stack>
#include <string>

using namespace std;

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