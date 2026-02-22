class Solution {
public:
    int solve(string s) {
        int maxDiff = 0, lastOne = -1;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1' && lastOne == -1) {
                lastOne = i;
            } else if (s[i] == '1') {
                maxDiff = max(maxDiff, i - lastOne);
                lastOne = i;
            }
        }

        return maxDiff;
    }

    int binaryGap(int n) {
        string num = bitset<32>(n).to_string().substr(
            bitset<32>(n).to_string().find('1'));
        return solve(num);
    }
};