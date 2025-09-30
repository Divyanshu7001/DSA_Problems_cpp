class Solution {
public:
    int solve(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        //vector<int> newNums(nums.size() - 1, -1);
        for (int i = 0; i < nums.size() - 1; i++) {
            nums[i] = (nums[i] + nums[i + 1]) % 10;
        }
        nums.pop_back();
        return solve(nums);
    }
    int triangularSum(vector<int>& nums) { return solve(nums); }
};