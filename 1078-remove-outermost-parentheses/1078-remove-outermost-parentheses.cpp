class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int depth = 0;
        
        for (char c : s) {
            if (c == '(') {
                if (depth > 0) {
                    res.push_back(c);
                }
                depth++;
            } else {
                depth--;
                if (depth > 0) {
                    res.push_back(c);
                }
            }
        }
        
        return res;
    }
};

// class Solution {
// public:
//     string removeOuterParentheses(string s) {
//         int n = s.length();
//         if (n == 1)
//             return "";

//         string res = "";
//         for (int i = 0; i < n; i++) {
//             cout<<res.back()<<" "<<s[i];
//             if (res.back() != s[i])
//                 res.push_back(s[i]);
//         }
//         return res;
//     }
// };