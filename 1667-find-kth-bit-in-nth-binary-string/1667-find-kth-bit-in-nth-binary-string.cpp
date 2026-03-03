class Solution {
public:
    string invert(string s) {
        for (int i = 0; i < s.length(); i++) {
            s[i] = (s[i] == '0' ? '1' : '0');
        }
        return s;
    }
    char findKthBit(int n, int k) {
        string prev = "0";
        int i = 1;
        while (i < n) {
            string modified = prev + "1";
            string inverted = invert(prev);
            reverse(inverted.begin(), inverted.end());
            modified += inverted;
            prev = modified;
            i++;
        }
        return prev[k-1];
    }
};