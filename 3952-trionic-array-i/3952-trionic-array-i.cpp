//T.C=O(N)
class Solution {
public:
    bool isTrionic(vector<int>& nums) {

        int i = 0, changeCount = 0, deflection = -1;

        while (i < nums.size() - 1) {
            if (nums[i] > nums[i + 1]) {
                if (i == 0)
                    return false;
                if (deflection == -1) {
                    deflection = i;
                    changeCount = 1;
                } else if (changeCount == 2)
                    return false;
            } else if (nums[i] < nums[i + 1]) {
                if (deflection != -1) {
                    if (changeCount == 1)
                        changeCount = 2;
                }
            } else if (nums[i] == nums[i + 1])
                return false;
            i++;
        }
        return changeCount == 2;
    }
};