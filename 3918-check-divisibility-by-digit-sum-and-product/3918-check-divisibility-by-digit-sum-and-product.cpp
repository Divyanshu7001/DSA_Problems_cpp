class Solution {
public:
    bool checkDivisibility(int n) {
        int dig_sum = 0, dig_mul = 1, tmp = n;
       
        while (tmp > 0) {
            int dig = tmp % 10;
            dig_sum += dig;
            dig_mul *= dig;
            tmp /= 10;
        }

        return n % (dig_sum + dig_mul) == 0;
    }
};