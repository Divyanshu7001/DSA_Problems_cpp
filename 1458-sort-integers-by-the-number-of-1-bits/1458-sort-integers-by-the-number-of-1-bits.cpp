class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        map<int, vector<int>> mp;
        for (int num : arr) {
            int noOnes = __builtin_popcount(num);
            mp[noOnes].push_back(num);
        }
        if (mp.size() == 1)
            return arr;
        vector<int> res;
        for (auto& p : mp) {
            for (int num : p.second)
                res.push_back(num);
        }
        return res;
    }
};