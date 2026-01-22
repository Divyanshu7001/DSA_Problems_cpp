class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int low = INT_MAX;
        int index = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] + nums[i + 1] < low) {
                low = nums[i] + nums[i + 1];
                index = i;
            }
        }
        return index;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int op = 0;

        while (!is_sorted(nums.begin(), nums.end())) {
            int index = minPairSum(nums);
            nums[index] = nums[index] + nums[index + 1];
            nums.erase(nums.begin() + index + 1);
            op++;
        }
        return op;
    }
};