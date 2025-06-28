// Simple Backtracking
// T.C=O(C(N,K))

// Not Optimal
// Time limit exceeds
//  class Solution {
//  public:
//      vector<int> result;
//      int maxSum = INT_MIN;
//      void backtrack(vector<int>& nums, int index, int k, vector<int>& temp,
//                     int currentSum) {
//          if (temp.size() == k) {
//              if (currentSum > maxSum) {
//                  maxSum = currentSum;
//                  result = temp;
//              }
//              return;
//          }

//         for (int i = index; i < nums.size(); i++) {
//             temp.push_back(nums[i]);
//             backtrack(nums, i + 1, k, temp, currentSum + nums[i]);
//             temp.pop_back();
//         }
//     }

//     vector<int> maxSubsequence(vector<int>& nums, int k) {
//         vector<int> temp;
//         backtrack(nums, 0, k, temp, 0);
//         return result;
//     }
// };

// Ordering lost of indices here
//  class Solution {
//  public:
//      vector<int> result;
//      vector<int> maxSubsequence(vector<int>& nums, int k) {
//          sort(nums.begin(),nums.end());
//          for(int i=0;i<k;i++){
//              result.push_back(nums[nums.size()-i-1]);
//          }

//         sort(result.begin(),result.end());
//         return result;
//     }
// };

// o(nlogn) approach with indices storing to keep the order
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {

        int n = nums.size();
        vector<pair<int, int>> vec(n);
        for (int i = 0; i < n; i++) {
            vec[i] = make_pair(i, nums[i]);
        }
        auto lambda = [](auto& p1, auto& p2) {
            return p1.second > p2.second; // Descending order sorting
        };
        sort(vec.begin(), vec.end(), lambda);

        sort(vec.begin(),
             vec.begin() +
                 k); // Guarantees that top k elements are sorted in order

        vector<int> result(k);
        for (int i = 0; i < k; i++) {
            result[i] = vec[i].second;
        }
        return result;
    }
};