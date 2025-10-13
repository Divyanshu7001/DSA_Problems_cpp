//T.C=O(NâK)
class Solution {
public:
    int n;
    bool isAnagram(string a, string b) {
        if (a.size() != b.size())
            return false; // early exit if lengths differ

        array<int, 26> freq = {0};
        for (char c : a)
            freq[c - 'a']++;
        for (char c : b)
            freq[c - 'a']--;
        for (int x : freq)
            if (x != 0)
                return false;
        return true;
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
        if (n == 2) {
            if (isAnagram(words[1], words[0])){
                words.erase(words.begin()+1);
                return words;
            }
            return words;
        }
        return solve(words);
    }
};