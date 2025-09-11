class Solution {
public:
    string sortVowels(string s) {
        string result = s;
        vector<int> asciiValues;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' ||
                s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' ||
                s[i] == 'u' || s[i] == 'U') {
                asciiValues.push_back((int)s[i]);
            }
        }

        if (asciiValues.size() == 0)
            return result;

        sort(asciiValues.begin(), asciiValues.end(), greater<int>());

        for (int i = 0; i < result.length(); i++) {
            if (result[i] == 'a' || result[i] == 'A' || result[i] == 'e' ||
                result[i] == 'E' || result[i] == 'i' || result[i] == 'I' ||
                result[i] == 'o' || result[i] == 'O' || result[i] == 'u' ||
                result[i] == 'U') {
                result[i] = asciiValues.back();
                asciiValues.pop_back();
            }
        }
        return result;
    }
};