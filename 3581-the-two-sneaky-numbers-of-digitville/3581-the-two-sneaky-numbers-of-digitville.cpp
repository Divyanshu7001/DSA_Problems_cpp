class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {

        vector<int> result;
        unordered_map<int, int> mp;

        for (int num : nums) {
            mp[num]++;
        }

        for (auto p : mp) {
            if (p.second > 1)
                result.push_back(p.first);
        }

        return result;
    }
};