class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return 1;

        int minEle = INT_MAX, minIdx, maxIdx, maxEle = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (nums[i] < minEle) {
                minEle = nums[i];
                minIdx = i;
            }
            if (nums[i] > maxEle) {
                maxEle = nums[i];
                maxIdx = i;
            }
        }

        int left = min(minIdx, maxIdx);
        int right = max(minIdx, maxIdx);

        return min({left + 1 + n - right, right + 1, n - left});
    }
};