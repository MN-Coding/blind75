/*
Problem: 20. Valid Parentheses
Time Complexity = O(n)
Space Complexity = O(n)
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(')');
            } else if (s[i] == '[') {
                st.push(']');
            } else if (s[i] == '{') {
                st.push('}');
            } else if (!st.empty() && s[i] == st.top()) {
                st.pop();
            } else {
                return false;
            }
        }
        return st.empty();
        
    }
};
