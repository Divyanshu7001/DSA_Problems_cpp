class Solution {
public:
    int MOD = 1e9 + 7;
    int numberOfWays(string corridor) {
        int n = corridor.length();
        if (n == 1)
            return 0;
        if (n == 2) {
            if (corridor[0] == 'S' && corridor[1] == 'S')
                return 1;
            return 0;
        }

        int count = 0, prefix = 0, ans = 1;
        for (char c : corridor) {
            if (c == 'S')
                prefix++;

            if (prefix == 2)
                count++;

            if (prefix == 3) {
                ans = (ans * 1LL * count) % MOD;
                count = 0;
                prefix = 1;
            }
        }

        if (prefix != 2)
            return 0;

        return ans;
    }
};