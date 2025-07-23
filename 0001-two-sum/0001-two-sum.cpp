// Brute force
// T.C=O(n2)
//  class Solution {
//  public:
//      vector<int> twoSum(vector<int>& nums, int target) {

//         for(int i=0;i<nums.size();i++){
//             for(int j=i+1;j<nums.size();j++){
//                 if(nums[i]+nums[j]==target){
//                     return {i,j};
//                 }
//             }
//         }
//         return {};
//     }
// };


// Two pointer approach
// T.C=O(nlogn)
// Sort and start doing sum and match ..if match..return the
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> seen; // value -> index

        for (int i = 0; i < nums.size(); ++i) {
            int need = target - nums[i]; // complement needed
            if (seen.find(need) != seen.end()) {
                return {seen[need], i};
            }
            // Store current number and its index
            seen[nums[i]] = i;
        }

        return {};
    }
};