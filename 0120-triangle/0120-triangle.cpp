class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(int currentRow, int IndexTaken, vector<vector<int>>& triangle) {
        if (currentRow == n) 
            return 0;

        // if already computed, return
        if (dp[currentRow][IndexTaken] != INT_MAX)
            return dp[currentRow][IndexTaken];

        int leftResult = triangle[currentRow][IndexTaken] +
                         solve(currentRow + 1, IndexTaken, triangle);

        int rightResult = triangle[currentRow][IndexTaken] +
                          solve(currentRow + 1, IndexTaken + 1, triangle);

        // store & return
        return dp[currentRow][IndexTaken] = 
               (leftResult <= rightResult ? leftResult : rightResult);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
        dp.assign(n, vector<int>(n, INT_MAX));
        return solve(0, 0, triangle);
    }
};



//T.C=O(2^N) => simple recursion explore -> TLE
// class Solution {
// public:
//     int n, result;
//     int solve(int currentRow, int IndexTaken, vector<vector<int>>& triangle) {
//         if (currentRow == n)
//             return 0;
//         int leftResult = triangle[currentRow][IndexTaken] +
//                      solve(currentRow + 1, IndexTaken, triangle);
//         int rightResult = triangle[currentRow][IndexTaken] +
//                       solve(currentRow + 1, IndexTaken + 1, triangle);
//         return leftResult <= rightResult ? leftResult : rightResult;
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         n = triangle.size();
//         if (n == 1)
//             return triangle[0][0];

//         int leftResult = triangle[0][0] + solve(1, 0, triangle);
//         int rightResult = triangle[0][0] + solve(1, 1, triangle);
//         return leftResult <= rightResult ? leftResult : rightResult;
//     }
// };