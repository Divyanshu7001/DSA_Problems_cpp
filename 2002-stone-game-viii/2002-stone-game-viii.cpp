class Solution {
public:
    vector<int> pref;
    int n;
    vector<int> dp;

    int stoneGameVIII(vector<int>& stones) {

        n = stones.size();
        pref.resize(n, 0);
        pref[0] = stones[0];

        for (int i = 1; i < n; i++)
            pref[i] = pref[i - 1] + stones[i];

        dp.resize(n, 0);
        // we need to bottom up loop from the end as we are feeling from help of
        // [i+1].
        dp[n - 1] = pref[n - 1];
        for (int i = n - 2; i >= 1; i--) {
            int take = pref[i] - dp[i + 1];
            int skip = dp[i + 1];

            dp[i] = max(take, skip);
        }
        return dp[1];
    }
};

// one test case fails due to recursion overhead
//  class Solution {
//  public:
//      vector<int> pref;
//      int n;
//      vector<int> dp;

//     int solve(int idx) {
//         if (idx == n - 1)
//             return pref[n-1];
//         if (dp[idx] != -1)
//             return dp[idx];

//         int take = pref[idx] - solve(idx + 1);
//         int skip = solve(idx + 1);

//         return dp[idx] = max(take, skip);
//     }

//     int stoneGameVIII(vector<int>& stones) {
//         n = stones.size();
//         pref.resize(n, 0);
//         dp.resize(n + 1, -1);
//         pref[0] = stones[0];

//         for (int i = 1; i < n; i++)
//             pref[i] = pref[i - 1] + stones[i];

//         return solve(1);
//     }
// };