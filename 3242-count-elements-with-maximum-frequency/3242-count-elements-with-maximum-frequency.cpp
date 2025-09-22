class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int& num : nums) {
            mp[num]++;
        }

        int maxFrequency = INT_MIN, count = 0;
        for (auto x : mp) {
            if (x.second > maxFrequency) {
                maxFrequency = x.second;
                count = 1;
            } else if (x.second == maxFrequency) {
                count++;
            }
        }

        return maxFrequency * count;
    }
};