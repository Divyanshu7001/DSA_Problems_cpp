class Solution {
public:
    string processStr(string s) {

        string res = "";
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (ch == '*') {
                if (!res.empty())
                    res.pop_back();
            } else if (ch == '#') {
                res.append(res);
            } else if (ch == '%') {
                reverse(res.begin(), res.end());
            } else
                res += ch;
        }

        return res;
    }
};