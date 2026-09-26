class Solution {
public:
    unordered_map<string, string> mp;
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
                s.replace(i, k - i + 1, mp.count(key) ? mp[key] : "?");
                i += (mp.count(key) ? mp[key].length() : 1);
                n = s.length();
                continue;
            }
            i++;
        }
        return s;
    }
};