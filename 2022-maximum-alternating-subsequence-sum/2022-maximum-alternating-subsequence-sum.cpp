// class Solution {
// public:
//     int n;
//     typedef long long ll;
//     vector<vector<ll>> dp;
//     ll solve(int idx, bool flag, vector<int>& nums) {
//         // flag true means plus else false
//         if (idx == n)
//             return 0;
//         int isEven = (flag == true);
//         if (dp[idx][isEven] != -1)
//             return dp[idx][isEven];

//         ll skip = solve(idx + 1, flag, nums);
//         ll take = solve(idx + 1, !flag, nums) +
//                    (isEven == 1 ? nums[idx] : -nums[idx]);

//         return dp[idx][isEven] = max(take, skip);
//     }

//     ll maxAlternatingSum(vector<int>& nums) {
//         n = nums.size();
//         dp.resize(n + 1, vector<ll>(2, -1));
//         return solve(0, true, nums);
//     }
// };

class Solution {
public:
    typedef long long ll;

    // t[i]can have two states..odd or even as length of current sequence
    // t[i][even]=current sequence if even with this value etc
    // NOTE:
    //  by adding current value, the sequence length alternates..so
    //{a1,a2,a3}
    // by adding a4..becomes even sequence..but by signal alternating=>
    // a1-a2+a3-a4
    //  state definitions=> t[i][even]=max(t[i-1][odd]-nums[i],t[i-1][even]) as
    //  coming of the new value in sequence is minus
    // t[i][odd]=max(t[i-1][even]+nums[i],t[i-1][odd])

    ll maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<ll>> dp(n + 1, vector<ll>(2, -1));
        dp[0][0] = nums[0];
        dp[0][1] = 0;
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][1] + nums[i], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][0] - nums[i], dp[i - 1][1]);
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};