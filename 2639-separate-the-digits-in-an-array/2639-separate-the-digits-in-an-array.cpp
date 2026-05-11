class Solution {
public:
    vector<int> res;
    void solve(string s) {
        for (int i = 0; i < s.size(); i++) {
            res.push_back(s[i] - '0');
        }
    }
    vector<int> separateDigits(vector<int>& nums) {
        for (int& num : nums) {
            solve(to_string(num));
        }
        return res;
    }
};