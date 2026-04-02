class Solution {
public:
    int m, n;
    int t[501][501][3];
    int solve(vector<vector<int>>& coins, int i, int j, int neuPower) {

        if (i == m - 1 && j == n - 1) {
            if (coins[i][j] < 0 && neuPower > 0) {
                return 0;
            }
            return coins[i][j];
        }

        if (i >= m || j >= n)
            return INT_MIN;

        if (t[i][j][neuPower] != INT_MIN)
            return t[i][j][neuPower];

        // Take current cell
        int take = coins[i][j] + max(solve(coins, i + 1, j, neuPower),
                                     solve(coins, i, j + 1, neuPower));

        // Skip current if possible
        int skip = INT_MIN;
        if (coins[i][j] < 0 && neuPower > 0) {
            int skipDown = solve(coins, i + 1, j, neuPower - 1);
            int skipRight = solve(coins, i, j + 1, neuPower - 1);

            skip = max(skipDown, skipRight);
        }

        return t[i][j][neuPower] = max(take, skip);
    }

    int maximumAmount(vector<vector<int>>& coins) {

        m = coins.size();
        n = coins[0].size();

        for (int i = 0; i < 501; i++) {
            for (int j = 0; j < 501; j++) {
                for (int k = 0; k < 3; k++) {
                    t[i][j][k] = INT_MIN;
                }
            }
        }
        return solve(coins, 0, 0, 2);
    }
};