class Solution {
public:
    bool solve(int num, int div) {
        int product = 1;
        while (num > 0) {
            int rem = num % 10;
            product *= rem;
            num /= 10;
        }
        return (product % div == 0);
    }

    int smallestNumber(int n, int t) {
        while (true) {
            if (solve(n, t))
                return n;
            else
                n++;
        }
        return n;
    }
};