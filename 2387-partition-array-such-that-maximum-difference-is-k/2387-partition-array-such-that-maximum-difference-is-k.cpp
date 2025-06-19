class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int resultCount = 1; // every individual element is already a
                             // subsequence

        int minValue = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] - minValue > k) {
                resultCount++;
                minValue = nums[i];
            }
        }

        return resultCount;
    }
};