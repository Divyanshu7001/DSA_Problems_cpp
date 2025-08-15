//T.C=O(n) <= O(15) => constant
class Solution {
public:
    const long long LIMIT = (1LL << 31) - 1;
    bool isPowerOfFour(int n) {
        if (n == 1)
            return true;
        for (long long i = 4; i < LIMIT; i <<= 2) {
            if (i == n) {
                return true;
                break;
            }
        }
        return false;
    }
};