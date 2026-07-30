class Solution {
public:
    int n;
    vector<vector<long long>> dp;
    long long solve(int idx, bool flag, vector<int>& nums) {
        // flag true means plus else false
        if (idx == n)
            return 0;
        int isEven = (flag == true);
        if (dp[idx][isEven] != -1)
            return dp[idx][isEven];

        long long skip = solve(idx + 1, flag, nums);
        long long take = solve(idx + 1, !flag, nums) +
                   (isEven == 1 ? nums[idx] : -nums[idx]);

        return dp[idx][isEven] = max(take, skip);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        dp.resize(n + 1, vector<long long>(2, -1));
        return solve(0, true, nums);
    }
};