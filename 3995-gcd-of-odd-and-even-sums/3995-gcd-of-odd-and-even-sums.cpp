class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        else
            return gcd(b, a % b);
    }

    int gcdOfOddEvenSums(int n) {
        int maxEven = 0, maxOdd = 0;

        int i = 1;
        while (i <= (2 * n)) {
            if (i % 2 != 0)
                maxOdd += i;
            else
                maxEven += i;

            i++;
        }

        return gcd(maxEven, maxOdd);
    }
};