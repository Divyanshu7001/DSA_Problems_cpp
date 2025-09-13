class Solution {
public:
    int maxFreqSum(string s) {

        unordered_map<char, int> mp;

        int maxConsonantFreq = 0, maxVowelFreq = 0;
        for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u') {
                maxVowelFreq = max(maxVowelFreq, ++mp[c]);
            } else {
                maxConsonantFreq = max(maxConsonantFreq, ++mp[c]);
            }
        }

        return maxVowelFreq + maxConsonantFreq;
    }
};