class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        vector<tuple<bool, bool, bool>> freq(26, {false, false, false});
        for (char& ch : word) {
            int val = (int)ch;
            if (val <= 90) {
                int idx = (val + 32) - 'a';
                auto& [first, second, third] = freq[idx];
                if (second == true && first == false) {
                    first = true;
                    third = true;
                }
                if (second == false)
                    first = true;
            } else {
                int idx = val - 'a';
                auto& [first, second, third] = freq[idx];
                if (first == true)
                    third = false;
                else
                    second = true;
            }
        }
        int res = 0;

        for (auto& p : freq) {
            if (get<2>(p) == true)
                res++;
        }

        return res;
    }
};