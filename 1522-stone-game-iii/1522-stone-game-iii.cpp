class Solution {
public:
    static constexpr int MIN = -50000001;
    static inline string s[] = {"Bob", "Tie", "Alice"};

    string stoneGameIII(vector<int>& A) {
        int n = A.size();
        vector<int> dp(n, MIN);

        auto maxDiff = [&](this auto&& maxDiff, int i) -> int {
            if (i == n) return 0;

            int& res = dp[i];
            if (res != MIN) return res;

            int sum = 0;

            for (int j = 1; j <= 3 && i + j <= n; j++) {
                sum += A[i + j - 1];
                res = max(res, sum - maxDiff(i + j));
            }

            return res;
        };

        int d = maxDiff(0);
        return s[(d > 0) - (d < 0) + 1];
    }
};

// class Solution {
// public:
//     int n;
//     vector<vector<vector<int>>> dp;

//     int solve(int i, int j, int k, vector<int>& stoneValue) {

//         if (i > j || i == n)
//             return 0;

//         int take_one = 0, take_two = 0, take_three = 0;

//         take_one =
//             stoneValue[i] + solve((i + 1 >= n ? n : i + 1), j+1, k+1, stoneValue);

//         if (j < n)
//             take_two = stoneValue[i] + stoneValue[j] +
//                        solve((i + 1 >= n ? n : i + 1), (j + 1 >= n ? n : j + 1),
//                              k, stoneValue);

//         if (k < n) {
//             cout << i << " " << j << " " << k << endl;
//             take_three =
//                 stoneValue[i] + stoneValue[j] + stoneValue[k] +
//                 solve((i + 1 >= n ? n : i + 1), (j + 1 >= n ? n : j + 1),
//                       (k + 1 >= n ? n : k + 1), stoneValue);
//         }

//         return max({take_one, take_two, take_three});
//     }

//     string stoneGameIII(vector<int>& stoneValue) {
//         n = stoneValue.size();
//         dp.resize(n, vector<vector<int>>(n, vector<int>(n, -1)));
//         int totalScore = accumulate(stoneValue.begin(), stoneValue.end(), 0);
//         int aliceScore = solve(0, 1, 2, stoneValue);
//         int bobScore = totalScore - aliceScore;

//         if (aliceScore > bobScore)
//             return "Alice";
//         else if (aliceScore == bobScore)
//             return "Tie";

//         return "Bob";
//     }
// };