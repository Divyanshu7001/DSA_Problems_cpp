// Simulation approach
// T.C=O(n2)
//  class Solution {
//  public:
//      bool check(vector<int>& nums, int count, int i, int dir) {
//          int idx = i;
//          vector<int> temp = nums;

//         while (idx >= 0 && idx < nums.size() && count > 0) {
//             if (temp[idx] > 0) {
//                 temp[idx]--;
//                 dir *= -1;
//                 if (temp[idx] == 0)
//                     count--;
//             }
//             idx += dir;
//         }

//         return count == 0;
//     }

//     int countValidSelections(vector<int>& nums) {

//         int result = 0, n = nums.size();

//         int count = 0;

//         for (int i = 0; i < n; i++)
//             if (nums[i] != 0)
//                 count++;

//         for (int i = 0; i < n; i++) {
//             if (nums[i] == 0) {
//                 if (check(nums, count, i, -1))
//                     result++;

//                 if (check(nums, count, i, 1))
//                     result++;
//             }
//         }

//         return result;
//     }
// };

// Optimal Approach according to left and right portion sum logic
// if left and right portion sum from any index is same..then result+=2 & if
// difference between sums is 1..then result+=1
class Solution {
public:
    int countValidSelections(vector<int>& nums) {

        int result = 0, n = nums.size();

        int curr = 0, S = accumulate(begin(nums), end(nums), 0);

        for (int i = 0; i < n; i++) {
            curr += nums[i];

            int left = curr;
            int right = S - left;

            if (nums[i] != 0)
                continue;

            if (left == right)
                result += 2;

            if (abs(left - right) == 1)
                result += 1;
        }

        return result;
    }
};