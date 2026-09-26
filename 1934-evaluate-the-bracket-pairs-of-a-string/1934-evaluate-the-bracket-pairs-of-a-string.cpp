class Solution {
public:
    unordered_map<string, string> mp;
    string solve(string& key) {
        string res = "?";
        if (mp.count(key))
            return mp[key];
        return res;
    }
    string evaluate(string s, vector<vector<string>>& knowledge) {
        for (auto& vec : knowledge)
            mp[vec[0]] = vec[1];

        string res = "";
        int n = s.length();
        if (n == 1)
            return s;
        int i = 0;
        while (i < n) {
            if (s[i] == '(') {
                i++;
                string key = "";
                while (s[i] != ')') {
                    key.push_back(s[i]);
                    i++;
                }
                res += solve(key);
                i++;
                continue;
            } else
                res.push_back(s[i]);
            i++;
        }
        return res;
    }
};