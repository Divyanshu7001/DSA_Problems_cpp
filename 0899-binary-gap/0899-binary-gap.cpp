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
        string num = "";

        // Convert to binary
        while (n > 0) {
            num.push_back((n % 2) + '0');
            n /= 2;
        }
        return solve(num);
    }
};