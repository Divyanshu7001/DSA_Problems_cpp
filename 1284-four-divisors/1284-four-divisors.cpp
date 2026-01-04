// T.C=O(n)+O(sqrt(n))=>O(n)
// S.C=O(n)

// Just take care of perfect square case i.e 36=6*6..so we might take 6 two
// times..which isnt good
class Solution {
public:
    int solve(int num) {
        int ans = 1 + num, divCount = 2;
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                ans += i;
                int other = num / i;
                if (other == i) {
                    divCount += 1;
                } else {
                    divCount += 2;
                    ans += other;
                }
                if (divCount > 4)
                    break;
            }
        }
        return divCount == 4 ? ans : 0;
    }

    int sumFourDivisors(vector<int>& nums) {

        int ans = 0;

        for (int num : nums)
            ans += solve(num);

        return ans;
    }
};