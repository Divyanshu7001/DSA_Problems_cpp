class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> minima(n, 0);

        minima[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            minima[i] = min(minima[i + 1], nums[i]);

        //cout<<minima[0];
        int localMax = nums[0];
        for (int i = 0; i < n; i++) {
            localMax = max(localMax, nums[i]);

            if (localMax - minima[i] <= k)
                return i;
        }

        return -1;
    }
};