//Bottom-up DP approach

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0); 

        for (int i = n - 1; i >= 0; i--) {
            int points = questions[i][0];
            int skip = questions[i][1];
            int next = i + skip + 1;
            long long solve = points + (next < n ? dp[next] : 0);
            long long skipQ = dp[i + 1];
            dp[i] = max(solve, skipQ);
        }

        return dp[0];
    }
};