class Solution {
public:
    int n, t[101][101];
    int solve(int i, int open, string s) {
        if (open < 0)
            return false;
        if (i == n)
            return open == 0;

        if (t[i][open] != -1)
            return t[i][open];

        if (s[i] == '(') {
            return t[i][open] = solve(i + 1, open + 1, s);
        } else if (s[i] == ')') {
            return t[i][open] = solve(i + 1, open - 1, s);
        }
        int takeOpen = 0, takeClose = 0, nothing = 0;
        takeOpen = solve(i + 1, open + 1, s);
        takeClose = solve(i + 1, open - 1, s);
        nothing = solve(i + 1, open, s);
        return t[i][open] = (takeOpen || takeClose || nothing);
    }

    bool checkValidString(string s) {
        n = s.length();
        memset(t, -1, sizeof(t));
        if (n == 1)
            return s[0] == '*' ? true : false;

        return solve(0, 0, s);
    }
};

// class Solution {
// public:
//     bool checkValidString(string s) {
//         int n = s.length(), openCount = 0, closeCount = 0, stars = 0;

//         if (n == 1)
//             return false;

//         for (int i = 0; i < n; i++) {
//             if (s[i] == '(')
//                 openCount++;
//             else if (s[i] == ')') {
//                 closeCount++;
//             } else
//                 stars++;

//             if (closeCount > openCount + stars)
//                 return false;
//         }
//         cout << openCount << " " << stars;
//         return true;
//     }
// };