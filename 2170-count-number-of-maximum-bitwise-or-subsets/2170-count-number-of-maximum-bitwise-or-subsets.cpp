class Solution {
public:
    int maxOr = 0;

    int calc(vector<int>& nums, int idx, int curr) {
        int n = nums.size();
        if (idx == n) {
            if (curr == maxOr) {
                return 1;
            }
            return 0;
        }
        int take = calc(nums, idx + 1, curr | nums[idx]);
        int notTake = calc(nums, idx + 1, curr);

        return take + notTake;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size(), mx = 0;
        for (auto x : nums)
            mx |= x;
        maxOr = mx;

        // Calculate current and update for idx=>0 to n-1 , curr
        return calc(nums, 0, 0);
    }
};