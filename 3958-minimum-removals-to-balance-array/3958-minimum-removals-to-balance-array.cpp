class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1)
            return 0;

        int i = 0, j = 0, maxBalance = 0;
        sort(nums.begin(), nums.end());

        while (i < n && j < n) {
            if ((long)nums[j] <= (long)nums[i] * k) {
                maxBalance = max(maxBalance, (j - i + 1));
                j++;
            } else
                i++;
        }
        return n - maxBalance;
    }
};