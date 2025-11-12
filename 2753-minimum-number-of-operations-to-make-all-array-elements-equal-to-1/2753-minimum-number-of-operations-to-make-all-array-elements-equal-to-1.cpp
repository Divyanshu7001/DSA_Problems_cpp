class Solution {
public:
    int minOperations(vector<int>& nums) {

        int n = nums.size();

        int count1 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1)
                count1++;
        }
        if (count1 > 0)
            return n - count1;

        int op = INT_MAX;
        for (int i = 0; i < n; i++) {
            int GCD = nums[i];
            for (int j = i + 1; j < n; j++) {
                GCD = gcd(GCD, nums[j]);

                if (GCD == 1) {
                    op = min(op, j - i);
                }
            }
        }

        if (op == INT_MAX)
            return -1;

        return op + (n - 1);
    }
};