class Solution {
public:
    int maxFreqSum(string s) {

        unordered_map<char, int> Vowelmp;
        unordered_map<char, int> Consonantmp;

        int maxConsonantFreq = 0, maxVowelFreq = 0;
        for (char c : s) {
            char ch = tolower(c);
            if (ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'u') {
                maxVowelFreq = max(maxVowelFreq, ++Vowelmp[ch]);
            } else {
                maxConsonantFreq = max(maxConsonantFreq, ++Consonantmp[ch]);
            }
        }

        return maxVowelFreq + maxConsonantFreq;
    }
};