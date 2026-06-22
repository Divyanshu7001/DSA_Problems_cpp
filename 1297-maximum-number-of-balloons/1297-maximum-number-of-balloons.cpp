class Solution {
public:
    int maxNumberOfBalloons(string text) {

        unordered_map<char, int> mp;
        for (char& ch : text) {
            if (ch == 'a' || ch == 'b' || ch == 'l' || ch == 'o' || ch == 'n')
                mp[ch]++;
        }

        if (mp.size() < 5)
            return 0;

        int res = INT_MAX;
        for (auto& [ch, freq] : mp) {
            res = min(res, (ch == 'l' || ch == 'o') ? freq / 2 : freq);
        }

        return res;
    }
};