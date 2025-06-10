class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> mp;
        for (char ch : s) {
            mp[ch]++;
        }

        vector<int> oddFreqs;
        vector<int> evenFreqs;

        for (auto& pair : mp) {
            int freq = pair.second;
            if (freq % 2 == 0)
                evenFreqs.push_back(freq);
            else
                oddFreqs.push_back(freq);
        }

        int maxDiff = INT_MIN;

        for (int odd : oddFreqs) {
            for (int even : evenFreqs) {
                maxDiff = max(maxDiff, odd - even);
            }
        }

        // If no valid odd/even pair was found
        return (maxDiff == INT_MIN) ? -1 : maxDiff;
    }
};
