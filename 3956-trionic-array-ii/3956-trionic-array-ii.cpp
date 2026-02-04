// Classic take or skip options problem => DP + Memoization

// trend 0 -> We are starting the trend here, So=>
// We can either take a perticular number and add it to the result to start the
// trend or skip it to next index

// trend 1 -> in this trend , check if the current number suits the trend
// according to the next index number, if passes condition -> add this and
// follow same trend if doesnt pass..add to result and change the trend

// trend 3 -> in the last trend, we can either take this index and call for next
// index solve call or end at this perticular index

class Solution {
public:
    typedef long long ll;
    int n;
    vector<vector<ll>> dp;
    ll solve(int i, int trend, vector<int>& nums) {

        if (i == n) {
            if (trend == 3) {
                return 0; // last index
            } else
                return LLONG_MIN / 2; // invalid
        }

        if (dp[i][trend] != LLONG_MIN)
            return dp[i][trend];

        ll take = LLONG_MIN / 2, skip = LLONG_MIN / 2;

        // skip
        if (trend == 0) {
            skip = solve(i + 1, 0, nums);
        }

        // At the last trend and we can end it here
        if (trend == 3) {
            take = nums[i]; // finish it here
        }

        if (i + 1 < n) {
            int curr = nums[i];
            int next = nums[i + 1];

            if (trend == 0 && next > curr) {
                take = max(take, curr + solve(i + 1, 1, nums));
            } else if (trend == 1) {
                if (next > curr) {
                    take = max(take, curr + solve(i + 1, 1, nums));
                } else if (next < curr) {
                    take = max(take, curr + solve(i + 1, 2, nums));
                }
            } else if (trend == 2) {
                if (next < curr) {
                    take = max(take, curr + solve(i + 1, 2, nums));
                } else if (next > curr) {
                    take = max(take, curr + solve(i + 1, 3, nums));
                }
            } else if (trend == 3 && next > curr) {
                take = max(take, curr + solve(i + 1, 3, nums));
            }
        }

        return dp[i][trend] = max(take, skip);
    }

    ll maxSumTrionic(vector<int>& nums) {
        n = nums.size();
        dp.assign(n + 1, vector<ll>(4, LLONG_MIN));
        return solve(0, 0, nums); // Starting from 0th index,trend=0
    }
};