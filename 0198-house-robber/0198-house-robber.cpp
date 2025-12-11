// //grredy..doesnt work
// class Solution {
// public:
//     int rob(vector<int>& nums) {

//         int n = nums.size();
//         if (n == 1)
//             return nums[0];
//         if (n == 2)
//             return max(nums[0], nums[1]);

//         // From size 3
//         auto it = max_element(nums.begin(), nums.end());
//         int index = it - nums.begin();
//         int res = nums[index]; // greedily taken the most value first
//         if (index == 0) {
//             index += 2;
//             res += nums[index];
//         } else if (index == n - 1) {
//             index -= 2;
//             res += nums[index];
//         } else {
//             int i, j;
//             i = j = index;
//             while (i > 0) {
//                 i -= 2;
//                 res += nums[i];
//             }
//             while (j < n - 2) {
//                 j += 2;
//                 res += nums[j];
//             }
//         }

//         return res;
//     }
// };

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0, prev1 = 0;

        for (int x : nums) {
            int pick = prev2 + x;
            int skip = prev1;
            int curr = max(pick, skip);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
