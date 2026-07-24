// With set..a bit more space complexity
//  class Solution {
//  public:
//      int uniqueXorTriplets(vector<int>& nums) {

//         int n = nums.size();

//         // store all pair XORs
//         unordered_set<int> st;
//         for (int i = 0; i < n; i++) {
//             for (int j = i; j < n; j++)
//                 st.insert(nums[i] ^ nums[j]);
//         }

//         // Find triplets
//         unordered_set<int> s2;
//         for (int pairXor : st) {
//             for (int& num : nums) {
//                 s2.insert(pairXor ^ num);
//             }
//         }

//         return s2.size();
//     }
// };

// with vector..space:O(maxElement)

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        int n = nums.size();
        int maxEl = *max_element(nums.begin(), nums.end());
        int T = 1;
        while (T <= maxEl)
            T <<= 1;

        // store all pair XORs
        vector<bool> s1(T, false);
        vector<bool> s2(T, false);
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++)
                s1[nums[i] ^ nums[j]] = true;
        }

        // Find triplets
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == false)
                continue;
            for (int& num : nums) {
                s2[i ^ num] = true;
            }
        }

        return count(s2.begin(), s2.end(), true);
    }
};