class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {

        int n = nums.size();
        vector<int> inc(n, 1);

        // Step 1: Compute increasing run lengths
        for (int i = 1; i < n; i++)
            if (nums[i] > nums[i - 1])
                inc[i] = inc[i - 1] + 1;

        // Step 2: Binary search on k
        int left = 1, right = n / 2, ans = 0;

        auto valid = [&](int k) {
            for (int i = 2 * k - 1; i < n; i++) {
                if (inc[i] >= k && inc[i - k] >= k)
                    return true;
            }
            return false;
        };

        while (left <= right) {
            int mid = (left + right) / 2;
            if (valid(mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};