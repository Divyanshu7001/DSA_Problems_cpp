class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, vector<int>> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]].push_back(i);
        }

        int index = INT_MAX;
        for (auto p : mp) {
            if (p.second.size() == 1)
                index = min(index, p.second[0]);
        }
        return index == INT_MAX ? -1 : index;
    }
};