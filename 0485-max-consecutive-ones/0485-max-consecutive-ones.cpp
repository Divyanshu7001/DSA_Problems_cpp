class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int res = 0, currLen = 0, n = nums.size();

        for (int num : nums) {
            if (num == 1)
                currLen++;
            else {
                res = max(res, currLen);
                currLen = 0;
            }
        }
        return max(res, currLen);
    }
};