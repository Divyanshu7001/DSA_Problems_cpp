class Solution {
public:
    int countBinarySubstrings(string s) {

        int res = 0, prevCount = 0, currCount = 1;

        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1])
                currCount++;
            else {
                res += min(prevCount, currCount);
                prevCount = currCount;
                currCount = 1;
            }
        }

        return res + min(prevCount, currCount);
    }
};