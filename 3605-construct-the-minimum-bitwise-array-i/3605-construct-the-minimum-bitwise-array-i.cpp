class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            bool found = false;
            int j = 1;
            while (j < nums[i]) {
                if ((j | (j + 1)) == nums[i]) {
                    nums[i] = j;
                    found = true;
                    break;
                }
                j++;
            }
            if (!found)
                nums[i] = -1;
            ;
        }
        return nums;
    }
};