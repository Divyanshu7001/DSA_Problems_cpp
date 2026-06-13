class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res = "";
        for (string& s : words) {
            int temp = 0;
            for (int i = 0; i < s.size(); i++) {
                temp += weights[s[i] - 'a'];
            }
            res.push_back('z' - (temp % 26));
        }
        return res;
    }
};