class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size(),localMax = INT_MIN;
        for (int i = 0; i < n; i++) {
            localMax = max(localMax, nums[i]);
            int localMin = INT_MAX;
            for (int j = i; j < n; j++) {
                localMin = min(localMin, nums[j]);
            }

            if (localMax - localMin <= k)
                return i;
        }
        return -1;
    }
};