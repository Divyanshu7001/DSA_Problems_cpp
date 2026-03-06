class Solution {
public:
    int solve(string& s) {
        int op = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                s[i] = s[i] == '0' ? '1' : '0';
                op++;
            }
        }
        return op;
    }
    int minOperations(string s) {
        string newString = s;
        bool zeroFirst = false;
        if (s[0] == '0')
            zeroFirst = true;
        s[0] = '0';
        newString[0] = '1';
        int zeroOp = solve(s);
        int oneOp = solve(newString);
        if (zeroFirst)
            oneOp++;
        else
            zeroOp++;
        return min(zeroOp, oneOp);
    }
};