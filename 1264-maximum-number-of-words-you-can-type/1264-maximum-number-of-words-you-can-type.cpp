class Solution {
public:
    unordered_set<char> brokenList;

    int solve(string word) {
        for (char& ch : word)
            if (brokenList.count(ch))
                return 0;

        return 1;
    }

    int canBeTypedWords(string text, string brokenLetters) {
        for (int i = 0; i < brokenLetters.length(); i++) 
            brokenList.insert(brokenLetters[i]);
        
        stringstream ss(text);
        string word;
        int result = 0;
        while (ss >> word)
            result += solve(word);
        return result;
    }
};