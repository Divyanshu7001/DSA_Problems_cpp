class Solution {
public:
    int maxProduct(int n) {
        int firstMax = INT_MIN, secondMax = INT_MIN;
        while (n > 0) {
            int dig = n % 10;
            if (dig > firstMax) {
                secondMax = firstMax;
                firstMax = dig;
            } else if (dig > secondMax && dig <= firstMax)
                secondMax = dig;
            n /= 10;
        }

        return firstMax * secondMax;
    }
};