class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        if (n < 2) return -1;

        // dp[i] stores the minimum length of a valid subarray in arr[0...i]
        vector<int> dp(n, INT_MAX);
        
        int sum = 0, left = 0, min_len = INT_MAX, ans = INT_MAX;

        for (int right = 0; right < n; ++right) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            if (sum == target) {
                int curr_len = right - left + 1;

                // Check if there is a valid non-overlapping subarray to the left
                if (left > 0 && dp[left - 1] != INT_MAX) {
                    ans = min(ans, curr_len + dp[left - 1]);
                }

                min_len = min(min_len, curr_len);
            }
            
            dp[right] = min_len;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};


//Pure sliding window -> 57/61 passed...failed on this one
// Input
// arr =
// [2,1,3,3,2,3,1]
// target =
// 6
// Stdout
// Trigger for: 0 2
// Trigger for: 4 6
// Output
// 6
// Expected
// 5
//cause-> cant have dp like take or skip in this one
// class Solution {
// public:
//     int minSumOfLengths(vector<int>& arr, int target) {
//         int n = arr.size();
//         if (n == 1)
//             return -1;

//         vector<int> pref(n, 0);
//         pref[0] = arr[0];
//         for (int i = 1; i < n; i++)
//             pref[i] = pref[i - 1] + arr[i];

//         int i = 0, j = 0, count = 0;
//         int len1 = INT_MAX, len2 = INT_MAX;

//         while (j < n) {
//             int currLen = (j - i + 1);
//             int currWinSum = pref[j] - ((i - 1 >= 0) ? pref[i - 1] : 0);

//             if (currWinSum == target) {
//                 if (count == 0) {
//                     len1 = currLen;
//                 } else if (count == 1) {
//                     len2 = currLen;
//                 } else {
//                     // If we already have 2, we can replace the larger one
//                     if (currLen < max(len1, len2)) {
//                         if (len1 > len2)
//                             len1 = currLen;
//                         else
//                             len2 = currLen;
//                     }
//                 }
//                 count++;
//                 i = j + 1; // as the current is already equal target..go to next
//                            // index
//             } else if (currWinSum > target) {
//                 while (currWinSum > target && i <= j) {
//                     currWinSum -= arr[i];
//                     i++;
//                 }
//                 if (i > j)
//                     j = i;
//                 continue;
//             }

//             j++;
//         }

//         return count < 2 ? -1 : (len1 + len2);
//     }
// };