// min-max game strategy / Game based strategy
// DP game strategy=>
// when your turn..think best possible result(max)
// when opposite turn...think worst result(min)
class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(vector<int>& nums, int i, int j) {
        if (i > j)
            return 0;

        if (i == j) {
            return nums[i];
        }
        if (dp[i][j] != -1)
            return dp[i][j];

        // you take the first choice index & expect minimum from the possibe
        // taken choices of oposition
        int take_first =
            nums[i] + min(solve(nums, i + 2, j), solve(nums, i + 1, j - 1));

        // you take the last choice index & expect minimum from the possibe
        // taken choices of oposition
        int take_last =
            nums[j] + min(solve(nums, i, j - 2), solve(nums, i + 1, j - 1));

        return dp[i][j] = max(take_first, take_last);
    }

    bool predictTheWinner(vector<int>& nums) {
        n = nums.size();
        dp.resize(n, vector<int>(n, -1));
        int total_score = accumulate(nums.begin(), nums.end(), 0);
        int player1_score = solve(nums, 0, n - 1);
        return player1_score >= (total_score - player1_score);
    }
};

// class Solution {
// public:
//     int n;
//     vector<vector<bool>> dp;

//     bool solve(vector<int>& nums, int i, int j, long player1Score,
//                long player2Score, int player) {

//         if (i == j) {
//             if (player == 1)
//                 player1Score += nums[i];
//             else
//                 player2Score += nums[j];

//             return player1Score >= player2Score;
//         }

//         bool take_first =
//             solve(nums, i + 1, j,
//                   (player == 1 ? player1Score + nums[i] : player1Score),
//                   (player == 2 ? player2Score + nums[i] : player1Score),
//                   player == 1 ? 2 : 1);
//         bool take_last =
//             solve(nums, i, j - 1,
//                   (player == 1 ? player1Score + nums[j] : player1Score),
//                   (player == 2 ? player2Score + nums[j] : player1Score),
//                   player == 1 ? 2 : 1);

//         return (take_first == true || take_last == true);
//     }

//     bool predictTheWinner(vector<int>& nums) {
//         return solve(nums, 0, nums.size() - 1, 0, 0, 1);
//     }
// };