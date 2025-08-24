class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0, maxLen = 0;
        bool usedZero = false;

        for (int right = 0; right < n; ++right) {
            if (nums[right] == 0) {
                if (!usedZero) {
                    // first zero we encounter, mark it as used
                    usedZero = true;
                } else {
                    // second zero -> shrink window from the left
                    while (nums[left] != 0) {
                        left++;
                    }
                    // pop the first zero
                    left++;
                    // now we can treat this new zero as "used"
                }
            }
            maxLen = max(maxLen, right - left + 1);
        }

        // delete one element (either the used zero or one '1')
        return maxLen - 1;

    }
};