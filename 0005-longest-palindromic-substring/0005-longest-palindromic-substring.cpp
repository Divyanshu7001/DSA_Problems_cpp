class Solution {
public:
    int solve(string& s, int i, int j) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            i--;
            j++;
        }
        return j - i - 1;
    }

    string longestPalindrome(string s) {

        int n = s.length();
        if (n <= 1)
            return s;

        int start = 0, maxLen = 1;

        for (int i = 0; i < n; i++) {
            int len1 = solve(s, i, i);

            int len2 = solve(s, i, i + 1);

            int currentMax = max(len1, len2);

            if (currentMax > maxLen) {
                start = i - (currentMax - 1) / 2;
                maxLen = currentMax;
            }
        }
        return s.substr(start, maxLen);
    }
};