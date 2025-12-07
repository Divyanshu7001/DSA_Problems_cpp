class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {

        vector<int> res;
        int i = 0;
        while (i < n) {
            res.push_back(nums[i]);
            res.push_back(nums[i + n]);
            i++;
        }
        return res;
    }
};