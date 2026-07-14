class Solution {
public:
    int t[201][201][201];
    int MOD = 1e9 + 7;
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        else
            return gcd(b, a % b);
    }

    int solve(vector<int>& nums, int i, int first, int second) {

        if (i == nums.size()) {
            bool bothNonEmpty = (first != 0 && second != 0);
            bool gcdMatch = (first == second);
            return bothNonEmpty && gcdMatch ? 1 : 0;
        }

        if (t[i][first][second] != -1)
            return t[i][first][second];

        int skip = solve(nums, i + 1, first, second);
        int put_in_1 = solve(nums, i + 1, gcd(first, nums[i]), second);
        int put_in_2 = solve(nums, i + 1, first, gcd(second, nums[i]));

        return t[i][first][second] = (0LL + skip + put_in_1 + put_in_2) % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        // solve-> numms,index we want to process,first sequence gcd,second
        // sequence gcd
        return solve(nums, 0, 0, 0);
    }
};