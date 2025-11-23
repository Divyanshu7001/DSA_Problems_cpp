// T.C=O(nlogN)
//  class Solution {
//  public:
//      int maxSumDivThree(vector<int>& nums) {

//         int sum = 0;

//         vector<int> remain1;
//         vector<int> remain2;

//         for (int num : nums) {
//             sum += num;

//             if (num % 3 == 1)
//                 remain1.push_back(num);
//             else if (num % 3 == 2)
//                 remain2.push_back(num);
//         }

//         if (sum % 3 == 0)
//             return sum;

//         sort(remain1.begin(), remain1.end());
//         sort(remain2.begin(), remain2.end());

//         int result = 0;
//         int remainder = sum % 3;
//         if (remainder == 1) {
//             int remove1 = remain1.size() >= 1 ? remain1[0] : INT_MAX;
//             int remove2 =
//                 remain2.size() >= 2 ? (remain2[0] + remain2[1]) : INT_MAX;

//             result = max(result, sum - min(remove1, remove2));
//         } else {
//             int remove1 = remain2.size() >= 1 ? remain2[0] : INT_MAX;
//             int remove2 =
//                 remain1.size() >= 2 ? (remain1[0] + remain1[1]) : INT_MAX;

//             result = max(result, sum - min(remove1, remove2));
//         }

//         return result;
//     }
// };

class Solution {
public:
    int solve(int i, int remain, vector<int>& nums, vector<vector<int>>& t) {

        if (i >= nums.size()) {
            if (remain == 0)
                return 0;
            return INT_MIN;
        }

        if (t[i][remain] != -1)
            return t[i][remain];

        int take = nums[i] + solve(i + 1, (remain + nums[i]) % 3, nums, t);
        int skip = solve(i + 1, remain, nums, t);

        return t[i][remain] = max(take, skip);
    }
    int maxSumDivThree(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> t(n, vector<int>(3, -1));
        return solve(0, 0, nums, t);
    }
};