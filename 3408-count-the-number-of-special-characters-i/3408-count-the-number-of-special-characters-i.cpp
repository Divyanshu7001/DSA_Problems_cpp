class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<pair<bool, bool>> freq(26, {false, false});
        for (char& ch : word) {
            int val = (int)ch;
            if (val <= 90) {
                freq[(val + 32) - 'a'].second = true;
                ;
            } else
                freq[val - 'a'].first = true;
        }
        int res = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i].first == true && freq[i].second == true)
                res++;
        }
        return res;
    }
};