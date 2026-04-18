class Solution {
public:
    int mirrorDistance(int n) {
        int num = n, rev = 0;
        if (num < 10)
            return 0;

        while (num > 0) {
            int dig = num % 10;
            rev = (rev * 10) + dig;
            num /= 10;
        }
        return abs(rev - n);
    }
};