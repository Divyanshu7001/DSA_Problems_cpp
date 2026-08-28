class Solution {
public:
    char midChar = '#';
    int halfLength = 0;
    vector<int> freq;
    string res = "";

    bool solve(string& curr, string& target, int i, bool greater) {
        if (curr.length() == halfLength) {
            string candidate = curr; // left half
            string rightHalf = curr;
            reverse(rightHalf.begin(), rightHalf.end());

            if (midChar != '#')
                candidate += midChar;
            candidate += rightHalf;

            if (candidate > target) {
                res = candidate;
                return true;
            }

            return false;
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (freq[ch - 'a'] == 0)
                continue;
            if (!greater && ch < target[i])
                continue;

            // do
            curr.push_back(ch);
            freq[ch - 'a']--;

            //explore
            bool isGreater = greater || ch > target[i];
            if (solve(curr, target, i + 1, isGreater))
                return true;

            //undo
            curr.pop_back();
            freq[ch - 'a']++;
        }

        return false;
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        freq.resize(26, 0);

        for (char& ch : s)
            freq[ch - 'a']++;

        int oddCount = 0;
        // counting odd chars & making half freq of the characters
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                oddCount++;
                midChar = i + 'a';
            }
            freq[i] /= 2;
        }
        
        if (oddCount > 1)
            return ""; // not possible to make a palindrome

        halfLength = n / 2;
        string curr = ""; // left half

        // curr,target,current index,isGreater
        solve(curr, target, 0, false);

        return res;
    }
};