class Solution {
public:
    bool solve(string &a, string& b) { return b < a; }

    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();

        int i = 0, j = 0;
        int oneCount = 0, minLen = INT_MAX;
        string res = "";

        while (j < n) {
            if (s[j] == '1') {
                oneCount++;
            }

            // Shrink window from the left while we have at least k ones
            while (oneCount >= k) {
                if (oneCount == k) {
                    int len = j - i + 1;
                    string tmp = s.substr(i, len);
                    
                    // Check if tmp is shorter, or equal length and lexicographically smaller
                    if (res == "" || len < res.length() || (len == res.length() && solve(res, tmp))) {
                        res = tmp;
                        minLen = len;
                    }
                }
                
                // over than k ..so shrink
                if (s[i] == '1') {
                    oneCount--;
                }
                i++;
            }
            j++;
        }

        return res;
    }
};