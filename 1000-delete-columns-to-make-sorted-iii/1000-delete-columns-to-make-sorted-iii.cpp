class Solution {
public:
    int minDeletionSize(vector<string>& strs) {

        int rows = strs.size(), cols = strs[0].size();

        vector<int> dp(cols, 1);
        // dp[i]=LIS ending at index i

        int LIS = 1;

        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < i; j++) {

                bool safe = true;
                for (int k = 0; k < rows; k++) {
                    if (strs[k][j] > strs[k][i]) {
                        safe = false;
                        break;
                    }
                }

                if (safe)
                    dp[i] = max(dp[i], dp[j] + 1);
            }

            LIS = max(LIS, dp[i]);
        }

        return cols - LIS;
    }
};