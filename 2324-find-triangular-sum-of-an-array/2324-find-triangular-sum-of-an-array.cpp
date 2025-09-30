class Solution {
public:
    int solve(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        vector<int> newNums;
        for (int i = 0; i < nums.size() - 1; i++) {
            newNums.push_back((nums[i] + nums[i + 1]) % 10);
        }
        return solve(newNums);
    }
    int triangularSum(vector<int>& nums) { return solve(nums); }
};