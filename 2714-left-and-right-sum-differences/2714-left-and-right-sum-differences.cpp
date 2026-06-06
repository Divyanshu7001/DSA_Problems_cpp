class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n, 0);
        for (int i = 1; i < n; i++) {
            leftSum[i] = nums[i - 1] + leftSum[i - 1];
        }

        int tempSum = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            leftSum[i] = abs(leftSum[i] - tempSum);
            tempSum += nums[i];
        }

        return leftSum;
    }
};