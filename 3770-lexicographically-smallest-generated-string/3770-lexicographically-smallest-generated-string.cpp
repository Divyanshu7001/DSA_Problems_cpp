// Fill the 'T' related indices first in the new word
// Any empty indices has to be filled with lexicographically smallest char
// Validate the "F" indices at last
// While filling 'T' indices..check for any clash/collision..if does, return " "

// while verifying 'F' indices...if something doesnt match the condition due to
// filled up lexico smallest chars, we should be flexible to change them
// accordingly Store the changable indices in a set or have a vector to store
// changable or non-changable indices with T & F while changing the problematic
// indices..make sure to make the smallest lexico string by changing from last
// indices of the supposed substring(right to left check and change..if not
// possible/..return " ")
class Solution {
public:
    bool isSame(string& word, string& str2, int i, int m) {
        for (int j = 0; j < m; j++, i++) {
            if (word[i] != str2[j])
                return false;
        }
        return true;
    }

    string generateString(string str1, string str2) {

        int n = str1.length(), m = str2.length();
        int N = n + m - 1;
        string word(N, '$');

        vector<bool> canChange(N, false);

        // Process the 'T'
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                int i_ = i;
                for (int j = 0; j < m; j++) {
                    if (word[i_] != '$' && word[i_] != str2[j])
                        return "";

                    word[i_] = str2[j];
                    i_++;
                }
            }
        }

        // Fill remaining spaces with 'a' for now
        for (int i = 0; i < N; i++) {
            if (word[i] == '$') {
                word[i] = 'a';
                canChange[i] = true;
            }
        }

        // process the 'F'
        // T.C=O(n*m)
        // S.C=O(N)
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                if (isSame(word, str2, i,
                           m)) { // if it comes as same,,we will try to change
                                 // it by check and changing the char from right
                                 // to left
                    bool ableTochange = false;
                    for (int k = i + m - 1; k >= i; k--) {
                        if (canChange[k] == true) {
                            word[k] = 'b';
                            ableTochange = true;
                            break;
                        }
                    }

                    if (ableTochange == false)
                        return "";
                }
            }
        }
        return word;
    }
};