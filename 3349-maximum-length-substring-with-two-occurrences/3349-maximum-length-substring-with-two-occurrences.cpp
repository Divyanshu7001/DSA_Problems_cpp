class Solution {
public:
    int maximumLengthSubstring(string s) {

        int n = s.length();
        if (n == 2)
            return 2;

        vector<int> mp(26, 0);
        int i = 0, j = 1, res = 1;
        mp[s[i] - 'a']++;
        while (j < n) {
            mp[s[j] - 'a']++;
            if (mp[s[j] - 'a'] > 2) {
                while (mp[s[j] - 'a'] > 2) {
                    mp[s[i] - 'a']--;
                    i++;
                }
            }
            res = max(res, j - i + 1);
            j++;
        }

        return res;
    }
};