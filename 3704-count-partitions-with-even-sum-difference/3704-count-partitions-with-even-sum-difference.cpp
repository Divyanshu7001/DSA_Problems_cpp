class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            int part1 = accumulate(nums.begin(), nums.begin() + i, 0);
            int part2 = accumulate(nums.begin() + i, nums.end(), 0);

            if (abs(part1 - part2) % 2 == 0)
                res += 1;
        }
        return res;
    }
};