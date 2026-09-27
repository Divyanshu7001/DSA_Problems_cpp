class Solution {
public:
    string reverseParentheses(string s) {

        int n = s.length();
        if (n == 1) {
            if (s[0] == '(' || s[0] == ')')
                return "";
            return s;
        }

        stack<int> skipLen;
        string res = "";
        for (char& ch : s) {
            if (ch == '(') {
                skipLen.push(res.length());
            } else if (ch == ')') {
                int l = skipLen.top();
                skipLen.pop();
                reverse(res.begin() + l, res.end());
            } else
                res.push_back(ch);
        }

        return res;
    }
};