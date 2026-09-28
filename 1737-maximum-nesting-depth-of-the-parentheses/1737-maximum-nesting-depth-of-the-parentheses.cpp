class Solution {
public:
    int maxDepth(string s) {
        int n = s.length(), res = 0, curr = 0;
        if (n == 1)
            return 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                curr++;
                res = max(res, curr);
            } else if (s[i] == ')') {
                if (curr > 0)
                    curr--;
                else
                    curr = 0;
            }
        }
        return res;
    }
};