class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        vector<string> words;
        string word;

        // Step 1: Split input into words
        while (iss >> word) {
            words.push_back(word);
        }

        // Step 2: Build reversed string
        std::string result;
        for (int i = words.size() - 1; i >= 0; i--) {
            result += words[i];
            if (i != 0)
                result += " "; // space
        }

        return result;
    }

};