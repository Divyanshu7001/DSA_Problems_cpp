class Solution {
public:
    bool isValid(string s) {
        if (s.length() == 1)
            return false;
        stack<char> st;
        for (char& ch : s) {
            if (ch == '(' || ch == '{' || ch == '[')
                st.push(ch);
            else {
                if (st.size() < 1)
                    return false;
                char topEle=st.top();
                if ((topEle == '(' && ch == ')') ||
                    (topEle == '{' && ch == '}') ||
                    (topEle == '[' && ch == ']'))
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty() == true;
    }
};