class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(int idx, int P, vector<int>& nums) {
        if (idx >= n)
            return 0;

        if (dp[idx][P + 1] != -1)
            return dp[idx][P + 1];

        int take = 0, skip = 0;
        if (P == -1 || nums[idx] > nums[P])
            take = 1 + solve(idx + 1, idx, nums);

        skip = solve(idx + 1, P, nums);

        return dp[idx][P + 1] = max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        dp.resize(n, vector<int>(n + 1, -1));

        return solve(0, -1, nums);
    }
};