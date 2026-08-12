class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        int n = nums.size();

        if (n == 1)
            return 1;

        unordered_map<int, int> mp;
        int i = 0, j = 1, res = 1;
        mp[nums[i]]++;
        while (j < n) {
            mp[nums[j]]++;
            if (mp[nums[j]] > k) {
                while (mp[nums[j]] > k) {
                    mp[nums[i]]--;
                    i++;
                }
            }
            res = max(res, j - i + 1);
            j++;
        }

        return res;
    }
};