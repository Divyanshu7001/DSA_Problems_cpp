class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> res(n);
        
        int value = 0;  // this holds the prefix value mod 5

        for (int i = 0; i < n; i++) {
            value = (value * 2 + nums[i]) % 5;
            res[i] = (value == 0);
        }

        return res;
    }
};
