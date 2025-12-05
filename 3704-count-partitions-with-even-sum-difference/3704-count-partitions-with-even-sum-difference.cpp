// T.C=O(n2)
//  class Solution {
//  public:
//      int countPartitions(vector<int>& nums) {
//          int res = 0;
//          for (int i = 0; i < nums.size() - 1; i++) {
//              int part1 = accumulate(nums.begin(), nums.begin() + i, 0);
//              int part2 = accumulate(nums.begin() + i, nums.end(), 0);

//             if (abs(part1 - part2) % 2 == 0)
//                 res += 1;
//         }
//         return res;
//     }
// };


//T.C=O(n)=>prefSum
class Solution {
public:
    int countPartitions(vector<int>& nums) {

        int n = nums.size();
        int res = 0;
        vector<int> prefSum(n, 0);
        prefSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefSum[i] = prefSum[i - 1] + nums[i];
        }

        for (int i = 0; i < n - 1; i++) {
            if (abs(prefSum[i] - (prefSum[n - 1] - prefSum[i])) % 2 == 0)
                res += 1;
        }
        return res;
    }
};