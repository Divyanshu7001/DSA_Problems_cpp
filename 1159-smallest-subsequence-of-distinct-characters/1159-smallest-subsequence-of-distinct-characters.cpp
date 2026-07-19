class Solution {
public:
    string smallestSubsequence(string s) {

        int n = s.length();
        string result;

        vector<bool> taken(26, false);
        vector<int> lastIdx(26);

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            lastIdx[ch - 'a'] = i;
        }

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            int idx = ch - 'a';

            if (taken[idx])
                continue;

            while (result.length() > 0) {
                char last_curr = result.back();
                if (last_curr > ch && lastIdx[last_curr - 'a'] > i) {
                    taken[last_curr - 'a'] = false;
                    result.pop_back();
                } else
                    break;
            }

            result.push_back(ch);
            taken[idx] = true;
        }

        return result;
    }
};