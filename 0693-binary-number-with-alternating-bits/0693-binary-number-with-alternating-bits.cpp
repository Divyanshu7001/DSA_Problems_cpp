class Solution {
public:
    bool isAlternate(string s) {
        int n = s.length();

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1])
                return false;
        }
        return true;
    }

    bool hasAlternatingBits(int n) {
        string s;
        if (n == 1) {
            s = "01";
            if (isAlternate(s))
                return true;
            else
                return false;
        }
        s = bitset<32>(n).to_string().substr(
            bitset<32>(n).to_string().find('1'));
        if (isAlternate(s))
            return true;

        return false;
    }
};