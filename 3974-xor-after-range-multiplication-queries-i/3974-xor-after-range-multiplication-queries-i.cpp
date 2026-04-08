class Solution {
public:
    int M = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        for (vector<int>& query : queries) {
            for (int i = query[0]; i <= query[1]; i += query[2])
                nums[i] = (1LL * nums[i] * query[3]) % M;
        }

        int res = nums[0];
        for (int i = 1; i < nums.size(); i++)
            res ^= nums[i];

        return res;
    }
};