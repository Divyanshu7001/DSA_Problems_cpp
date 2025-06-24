// Simulation approach
// T.C=O(n2)
// Just good for small array inputs
//  class Solution {
//  public:
//      vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
//          vector<int> result;
//          int n = nums.size();
//          vector<int> store;
//          for (int i = 0; i < n; i++) {
//              if (nums[i] == key)
//                  store.push_back(i);
//          }

//         for (int i = 0; i < n; i++) {
//             for (int idx : store) {
//                 if (abs(i - idx) <= k) {
//                     result.push_back(i);
//                     break;
//                 }
//             }
//         }

//         sort(result.begin(), result.end());
//         return result;
//     }
// };

// Optimal automatically sorted answer
// Usage of k is done wrt j index
// you can take min j-k and max j+k

// starting point of inner loop after getting the index matching to key
// starting point=j-k
// ending point=j+k
// keep pushing..it will automatically be sorted
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> result;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {
                int starting_point = max(i - k, 0);
                int ending_point = min(i + k, n - 1);
                // Prevent duplicates if last insertion overlapped
                if (!result.empty() && result.back() >= starting_point) {
                    starting_point = result.back() + 1;
                }
                while (starting_point <= ending_point) {
                    result.push_back(starting_point);
                    starting_point++;
                }
            }
        }

        return result;
    }
};
