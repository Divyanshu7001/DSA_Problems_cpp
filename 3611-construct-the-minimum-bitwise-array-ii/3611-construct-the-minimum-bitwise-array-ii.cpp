class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == 2) {
                nums[i] = -1;
                continue;
            }
            bool found = false;
            for (int j = 0; j < 32; j++) {
                // check to see if jth bit is set
                if ((nums[i] & (1 << j)) > 0) {
                    continue;
                }

                // the first jth bit with 0 value is found
                int prev = j - 1; // flip the last found 1
                int x = (nums[i] ^ (1 << (j - 1)));
                nums[i] = x;
                found = true;
                break;
            }
            if (!found)
                nums[i] = -1;
        }
        return nums;
    }
};