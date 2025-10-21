class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxElement = *max_element(nums.begin(), nums.end()) + k;

        vector<int> freq(maxElement + 1, 0);

        for (int& num : nums) {
            freq[num]++;
        }

        // Cumulative sum
        for (int i = 1; i <= maxElement; i++) {
            freq[i] += freq[i - 1];
        }

        int result = 0;
        for (int target = 0; target <= maxElement; target++) {
            if (freq[target] == 0)
                continue;

            int leftNum = max(0, target - k),
                rightNum = min(maxElement, target + k);

            int totalCount =
                freq[rightNum] - (leftNum > 0 ? freq[leftNum - 1] : 0);

            int targetCount =
                freq[target] - (target > 0 ? freq[target - 1] : 0);

            int needConversions = totalCount - targetCount;

            int maxPossibleFreq =
                targetCount + min(needConversions, numOperations);

            result = max(result, maxPossibleFreq);
        }

        return result;
    }
};