class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int ans = nums[0], freq = 1, n = nums.size();

        for (int i = 1; i < n; i++) {
            if (nums[i] == ans) {
                freq++;
            } else {
                freq--;
            }
            if (freq == 0) {
                ans = nums[i];
                freq = 1;
            }
        }
        cout << ans << endl;
        int count = 0;
        for (int val : nums) {
            if (val == ans) {
                count++;
            }
        }

        if (count > n / 2) {
            return ans;
        }
        return -1;
    }
};