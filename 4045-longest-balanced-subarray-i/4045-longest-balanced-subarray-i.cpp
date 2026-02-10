class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size(), res = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<int> odd, even;

            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 0)
                    even.insert(nums[j]);
                else
                    odd.insert(nums[j]);

                if (odd.size() == even.size())
                    res = max(res, j - i + 1);
            }
        }
        return res;
    }
};