class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        //vector<int> res;
        for (int i=0;i<nums.size();i++) {
            bool found = false;
            for (int j = 1; j < nums[i]; j++) {
                if ((j | (j + 1)) == nums[i]) {
                    nums[i]=j;
                    found = true;
                    break;
                }
            }
            if (!found)
                nums[i]=-1;;
        }
        return nums;
    }
};