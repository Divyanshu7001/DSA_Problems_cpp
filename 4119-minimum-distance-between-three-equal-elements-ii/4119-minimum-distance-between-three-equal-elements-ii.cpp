class Solution {
public:
    int solve(unordered_map<int, vector<int>>& mp) {
        int res = INT_MAX;
        for (auto& m : mp) {
            vector<int>& indexes = m.second;
            int indexSize = indexes.size();
            if (indexSize >= 3) {
                for (int i = 0; i < indexSize - 2; i++) {
                    int a = indexes[i], b = indexes[i + 1], c = indexes[i + 2];
                    res = min(res, abs(a - b) + abs(b - c) + abs(c - a));
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }

    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return -1;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        return solve(mp);
    }
};