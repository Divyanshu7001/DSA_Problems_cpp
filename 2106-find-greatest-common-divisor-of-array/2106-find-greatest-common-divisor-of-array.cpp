class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        else
            return gcd(b, a % b);
    }

    int findGCD(vector<int>& nums) {
        return gcd(*min_element(begin(nums), end(nums)),
                   *max_element(begin(nums), end(nums)));
    }
};