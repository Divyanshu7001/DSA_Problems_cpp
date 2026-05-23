class Solution {
public:
    bool check(vector<int>& nums) {

        int n = nums.size();
        bool rotFlag = false;

        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                if (!rotFlag)
                    rotFlag = true;
                else
                    return false;
            }
        }

        return true;
    }
};