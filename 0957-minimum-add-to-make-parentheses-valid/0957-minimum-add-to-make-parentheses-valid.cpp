class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        if (n == 1)
            return 1;
        int open = 0, res = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                if (open < 0) {
                    res += -1 * open;
                    open = 1;
                    continue;
                } 
                open++;
            } else
                open--;
        }
        return res + abs(open);
    }
};