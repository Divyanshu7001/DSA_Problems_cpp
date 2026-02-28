class Solution {
public:
    int concatenatedBinary(int n) {
        int M = 1e9 + 7;
        if (n == 1)
            return 1;
        long result = 0;
        for (int i = 1; i <= n; i++) {
            int digits = log2(i) + 1;
            result = ((result << digits) % M + i) % M;
        }

        return result;
    }
};