class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words,vector<int>& groups) {
        vector<string> res;
        res.push_back(words[0]);
        int prevGroup = groups[0];

        for (int i = 1; i < words.size(); ++i) {
            if (groups[i] != prevGroup) {
                res.push_back(words[i]);
                prevGroup = groups[i];
            }
        }
        return res;
    }
};