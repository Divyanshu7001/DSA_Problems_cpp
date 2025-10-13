class Solution {
public:
    int n;
    bool isAnagram(string a, string b) {
        if (a.size() != b.size())
            return false; // early exit if lengths differ
        unordered_map<char, int> mp1, mp2;
        for (char ch : a)
            mp1[ch]++;

        for (char ch : b)
            mp2[ch]++;

        return mp1 == mp2;
    }
    vector<string> solve(vector<string>& words) {
        int m = words.size();
        for (int i = 1; i < m; i++) {
            if (isAnagram(words[i], words[i - 1])) {
                words.erase(words.begin() + i);
                return solve(words);
            }
        }
        return words;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        n = words.size();
        if (n == 1)
            return words;

        return solve(words);
    }
};