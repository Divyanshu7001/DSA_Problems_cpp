class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(int i, int j, vector<int>& piles) {
        if (i > j)
            return 0;
        if (i == j)
            return piles[i];
        if (dp[i][j] != -1)
            return dp[i][j];

        int take_first =
            piles[i] + min(solve(i + 2, j, piles), solve(i + 1, j - 1, piles));
        int take_last =
            piles[j] + min(solve(i, j - 2, piles), solve(i + 1, j - 1, piles));

        return dp[i][j] = max(take_first, take_last);
    }

    bool stoneGame(vector<int>& piles) {
        n = piles.size();
        dp.resize(n, vector<int>(n, -1));
        int totalPiles = accumulate(piles.begin(), piles.end(), 0);
        int aliceScore = solve(0, n - 1, piles);
        //cout<<aliceScore<<endl;
        return aliceScore > (totalPiles - aliceScore);
    }
};