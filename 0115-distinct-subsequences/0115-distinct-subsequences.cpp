// normal recursion+memo
// options to take or skip when index characters match...else skip anyway

// forward matching
//  class Solution {
//  public:
//      int dp[1001][1001];
//      int solve(string& s, string& t, int i, int j) {
//          if (j == t.length())
//              return 1;
//          if (i == s.length())
//              return 0;

//         if (dp[i][j] != -1)
//             return dp[i][j];
//         if (s[i] == t[j])
//             return dp[i][j] = solve(s, t, i + 1, j + 1) + solve(s, t, i + 1,
//             j);
//         else
//             return dp[i][j] = solve(s, t, i + 1, j);

//         return -1;
//     }

//     int numDistinct(string s, string t) {
//         for (int i = 0; i < 1001; i++) {
//             for (int j = 0; j < 1001; j++)
//                 dp[i][j] = -1;
//         }
//         return solve(s, t, 0, 0);
//     }
// };

// backward matching..length match
class Solution {
public:
    int dp[1001][1001];
    int solve(string& s, string& t, int m, int n) {
        if (n == 0)
            return 1;
        if (m == 0)
            return 0;

        if (dp[m][n] != -1)
            return dp[m][n];

        if (s[m - 1] == t[n - 1])
            return dp[m][n] = solve(s, t, m - 1, n - 1) + solve(s, t, m - 1, n);
        else
            return dp[m][n] = solve(s, t, m - 1, n);

        return -1;
    }

    int numDistinct(string s, string t) {
        for (int i = 0; i < 1001; i++) {
            for (int j = 0; j < 1001; j++)
                dp[i][j] = -1;
        }
        return solve(s, t, s.length(), t.length());
    }
};