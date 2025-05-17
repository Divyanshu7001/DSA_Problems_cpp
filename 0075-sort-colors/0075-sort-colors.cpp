class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> freq(3, 0);

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                freq[0]++;
            } else if (nums[i] == 1) {
                freq[1]++;
            } else
                freq[2]++;
        }
        int index = 0;
        for (int color = 0; color < 3; color++) {
            for (int count = 0; count < freq[color]; count++) {
                nums[index] = color;
                index++;
            }
        }
    }
};