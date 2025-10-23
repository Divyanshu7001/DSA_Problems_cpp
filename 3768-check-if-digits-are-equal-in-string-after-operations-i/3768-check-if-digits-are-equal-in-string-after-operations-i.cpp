class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() > 2) {
            for (int i = 0; i < s.size(); i++) {
                s[i] = (char)(((s[i] - '0') + (s[i + 1] - '0')) % 10 + '0');
                if (i == s.size() - 1)
                    s.erase(i, i);
            }
        }

        return s[0] - '0' == s[1] - '0';
    }
};