// Logic:
// Supposing here for ideal case where when two numbers sum % k = 0
// For each number...we will check other numbers storing their rem and their
// possiblities if any number % k not equal to 0...we will get the need of it to
// become a number whose modulo = 0 get the newLength as dp[need]+1 ..increasing
// that value's frequency

// keep updating the maxLength
// if maxLength>=2..means there is a subsequence where two or more values can be
// added to become a number whose modulo = 0
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {

        int maxLength = 0;

        for (int val = 0; val < k; val++) {
            vector<int> dp(k, 0);
            for (int num : nums) {
                int rem = num % k;
                int need = (val - rem + k) %
                           k; // Hoping for ideal case here where num %k =0...if
                              // not..we get the need to do that
                int newLength = dp[need] + 1;
                dp[rem] = max(dp[rem], newLength);
                maxLength = max(maxLength, dp[rem]);
            }
        }
        return maxLength >= 2 ? maxLength : 0;
    }
};