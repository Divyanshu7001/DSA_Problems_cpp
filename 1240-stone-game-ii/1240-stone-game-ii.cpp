class Solution {
public:
    int n;
    int t[2][101][101];

    int solve(int player, int idx, int M, vector<int>& piles) {
        if (idx >= n)
            return 0;
        if (t[player][idx][M] != -1)
            return t[player][idx][M];

        int result = (player == 0) ? -1 : INT_MAX, stones = 0;
        for (int i = 1; i <= min(2 * M, n - idx); i++) {
            if (player == 0) {
                stones += piles[idx + i - 1];
                result= max(result,stones+solve(1,idx+i,max(M,i),piles));
            } else {
                result = min(result, solve(0, idx + i, max(M, i), piles));
            }
        }

        return t[player][idx][M] = result;
    }

    int stoneGameII(vector<int>& piles) {
        memset(t, -1, sizeof(t));
        n = piles.size();
        // supposing alice=0th player,bob=1th player
        return solve(0, 0, 1, piles);
    }
};