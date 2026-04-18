class Solution {
public:
    int mirrorDistance(int n) {
        int num = n, rev = 0;
        if (num < 10)
            return 0;

        while (num > 0) {
            rev = (rev * 10) + (num % 10);
            num /= 10;
        }
        return abs(rev - n);
    }
};