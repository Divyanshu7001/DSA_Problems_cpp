class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int change = num % n;
            int idx = (i + change + n) % n;
            res[i] = nums[idx];
        }

        return res;
    }
};