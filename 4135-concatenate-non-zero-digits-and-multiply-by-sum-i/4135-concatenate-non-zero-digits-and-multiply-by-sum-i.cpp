class Solution {
public:
    long long sumAndMultiply(int n) {

        long long res = 0; 
        int sum = 0, pow = 1;
        while (n > 0) {
            int rem = n % 10;
            n /= 10;
            if (rem == 0)
                continue;

            res = (rem * pow) + res;
            pow *= 10;
            sum += rem;
        }
        return res * sum;
    }
};