class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> c(26, 0);
        for (int i = 0; i < s.size(); i++) {
            c[s[i] - 'a']++;
        }

        for (char& p : s) {
            if (c[p - 'a'] == 1)
                return s.find(p);
        }
        return -1;
    }
};