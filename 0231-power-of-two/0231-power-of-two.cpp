class Solution {
public:
    bool checkPower(int n, int a) {
        auto result = pow(2, a);
        if (result == n) {
            return true;
        } else if (result > n) {
            return false;
        } else
            return checkPower(n, a + 1);
    }
    bool isPowerOfTwo(int n) {
        if (n == 1 || n == 2)
            return true;
        bool result = checkPower(n, 2);
        return result;
    }
};