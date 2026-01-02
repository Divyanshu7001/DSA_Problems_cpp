class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {

        int n = nums.size();
        int k = n / 2;

        unordered_map<int, int> mp;

        for (int n : nums)
            mp[n]++;

        for (auto& p : mp) {
            if (p.second == k)
                return p.first;
        }
        return 0;
    }
};