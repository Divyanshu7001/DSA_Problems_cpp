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
        int n = s.length();
        if (n == 1)
            return s;

        for (auto& vec : knowledge)
            mp[vec[0]] = vec[1];

        int i = 0;
        while (i < n) {
            if (s[i] == '(') {
                int k = i;
                k++;
                string key = "";
                while (s[k] != ')') {
                    key.push_back(s[k]);
                    k++;
                }
                string newVal = solve(key);
                s.replace(i, k - i + 1, newVal);
                i += newVal.length();
                n = s.length();
                continue;
            }
            i++;
        }
        return s;
    }
};