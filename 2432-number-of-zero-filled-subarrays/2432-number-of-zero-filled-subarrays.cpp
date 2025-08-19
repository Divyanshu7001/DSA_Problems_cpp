class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result = 0, count = 0;
        for (int num : nums) {
            if (num == 0) {
                count++;          // extend zero streak
                result += count;  // add all subarrays ending here
            } else {
                count = 0;        // reset streak
            }
        }
        return result;
    }
};

// class Solution {
// public:
//     long long solve(vector<int>& nums, int currentSubarrayLength,
//                     long long& result) {
//         int currentSubarrayCount = 0, tempLength = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] == 0) {
//                 tempLength++;
//                 for (int start = i + 1; start < nums.size(); start++) {
//                     if (nums[start] == 0) {
//                         tempLength++;
//                         if (tempLength == currentSubarrayLength) {
//                             currentSubarrayCount++;
//                             tempLength = 0;
//                             i = start;
//                         }
//                     } else {
//                         tempLength = 0;
//                         i = start;
//                     }
//                 }
//             }
//         }
//         if (currentSubarrayCount == 0)
//             return result;
//         else {
//             result += currentSubarrayCount;
//             return solve(nums, currentSubarrayLength + 1, result);
//         }
//     }
//     long long zeroFilledSubarray(vector<int>& nums) {
//         if (nums.size() == 1) {
//             if (nums[0] == 0)
//                 return 1;
//             else
//                 return 0;
//         }

//         long long result = 0;
//         // do simple addition for 1 length subarray
//         for (int& num : nums) {
//             if (num == 0)
//                 result++;
//         }
//         // if no1 length subarray..return from there
//         // if we get it..start doing recusive run
//         if (result == 0)
//             return 0;
//         else
//             return solve(nums, 2, result);
//     }
// };