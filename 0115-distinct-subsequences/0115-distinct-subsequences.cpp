class Solution {
public:
    int dp[1001][1001];
    int solve(string& s, string& t, int i, int j) {
        if (j == t.length())
            return 1;
        if (i == s.length())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == t[j])
            return dp[i][j] = solve(s, t, i + 1, j + 1) + solve(s, t, i + 1, j);
        else
            return dp[i][j] = solve(s, t, i + 1, j);

        return -1;
    }

    int numDistinct(string s, string t) {
        for (int i = 0; i < 1001; i++) {
            for (int j = 0; j < 1001; j++)
                dp[i][j] = -1;
        }
        return solve(s, t, 0, 0);
    }
};