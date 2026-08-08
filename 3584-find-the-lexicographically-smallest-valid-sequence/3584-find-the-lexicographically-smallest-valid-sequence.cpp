class Solution {
public:
    vector<int> validSequence(string word1, string word2) {

        int n = word1.length(), m = word2.length();

        vector<int> rightSideMatchedLength(n, 0);

        int rightMatched = 0, i = n - 1, j = m - 1;
        while (i >= 0) {
            if (j >= 0 && word1[i] == word2[j]) {
                rightMatched++;
                j--;
            }
            rightSideMatchedLength[i] = rightMatched;
            i--;
        }

        vector<int> res;
        bool canChange = true;

        i = 0, j = 0;
        while (i < n && j < m) {
            if (word1[i] == word2[j]) {
                res.push_back(i);
                j++;
            } else if (canChange == true && i + 1 < n &&
                       (rightSideMatchedLength[i + 1] >= m - j - 1)) {
                res.push_back(i);
                j++;
                canChange = false;
            }

            i++;
        }

        return j == m ? res : vector<int>();
    }
};