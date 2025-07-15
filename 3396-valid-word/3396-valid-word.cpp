class Solution {
public:
    bool isValid(string word) {
        bool hasVowel = false, hasConsonent = false;

        if (word.length() < 3) {
            return false;
        }

        for (char ch : word) {
            if (!isalnum(ch)) {
                return false;
            } else if (isalpha(ch)) {
                ch = tolower(ch);
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' ||
                    ch == 'u')
                    hasVowel = true;
                else
                    hasConsonent = true;
            }
        }
        return hasVowel && hasConsonent;
    }
};