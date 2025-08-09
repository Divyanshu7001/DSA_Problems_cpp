//T.c=O(logn)
// class Solution {
// public:
//     bool checkPower(int n, int a) {
//         auto result = pow(2, a);
//         if (result == n) {
//             return true;
//         } else if (result > n) {
//             return false;
//         } else
//             return checkPower(n, a + 1);
//     }
//     bool isPowerOfTwo(int n) {
//         if (n == 1 || n == 2)
//             return true;
//         bool result = checkPower(n, 2);
//         return result;
//     }
// };


// In binary representation, powers of two have a distinctive property:

// If n is a power of two, it contain exactly one bit set to 1.
// then, if we perform AND operation of n with nâ1, it will flip the set bit. ââ
// This unique pattern allows us to detect powers of two efficiently using bitwise operations.
//T.C=O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};