class Solution {
public:
    bool checkBalance(vector<int>& freq) {
        int common = 0;
        for (int fq : freq) {
            if (fq == 0)
                continue;

            if (common == 0)
                common = fq;
            else if (fq != common)
                return false;
        }
        return true;
    }

    int longestBalanced(string s) {
        int n = s.length(), res = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                if (checkBalance(freq))
                    res = max(res, j - i + 1);
            }
        }
        return res;
    }
};