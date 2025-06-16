class Solution {
public:
    int maximumDifference(vector<int>& nums) {

        int maxDifference = -1;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (i < j && (nums[i] < nums[j]) &&
                    ((nums[j] - nums[i]) > maxDifference)) {
                    maxDifference = nums[j] - nums[i];
                }
            }
        }
        return maxDifference;
    }
};