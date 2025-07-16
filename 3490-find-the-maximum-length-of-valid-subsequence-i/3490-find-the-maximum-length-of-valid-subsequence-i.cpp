// Logic:
// Work on Even parity,odd parity & alternating parity
// Compare and know the longest length

class Solution {
public:
    int maximumLength(vector<int>& nums) {

        int n = nums.size();

        int countEven = 0; // Length of even numbers subsequence
        int countOdd = 0;  // Length of odd numbers subsequence

        for (auto& num : nums) {
            if (num % 2 == 0) {
                countEven++;
            } else {
                countOdd++;
            }
        }

        int parity = nums[0] % 2;
        int countAlternating =
            1; // Length of alternating parity numbers subsequence

        for (int i = 1; i < n; i++) {
            int currentParity = nums[i] % 2;
            if (currentParity != parity) {
                countAlternating++;
                parity = currentParity;
            }
        }

        return max({countOdd, countEven, countAlternating});
    }
};