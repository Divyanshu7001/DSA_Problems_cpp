// T.C=O(m*n)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        if (amount < 1)
            return 0;

        vector<int> minCoinsDP(amount+1);
        minCoinsDP[0] = 0;
        for (int i = 1; i <= amount; i++) {
            minCoinsDP[i] = INT_MAX;

            for (int coin : coins) {
                if (coin <= i && minCoinsDP[i - coin] != INT_MAX) {
                    minCoinsDP[i] =
                        min(minCoinsDP[i], 1 + minCoinsDP[i - coin]);
                }
            }
        }
        if (minCoinsDP[amount] == INT_MAX)
            return -1;
        return minCoinsDP[amount];
    }
};