// Brute Force

// class Solution {
// public:
//     int maximumDifference(vector<int>& nums) {

//         int maxDifference = -1;

//         for (int i = 0; i < nums.size(); i++) {
//             for (int j = i + 1; j < nums.size(); j++) {
//                 if (i < j && (nums[i] < nums[j]) &&
//                     ((nums[j] - nums[i]) > maxDifference)) {
//                     maxDifference = nums[j] - nums[i];
//                 }
//             }
//         }
//         return maxDifference;
//     }
// };


//Normal solution - O(n)
class Solution {
public:
    int maximumDifference(vector<int>& nums) {

        int minElement = nums[0]; // nums[i] taken to be minimum element at
                                  // first
        int maxDifference = -1;

        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] > minElement) {
                maxDifference = max(maxDifference, nums[j] - minElement);
            } else {
                minElement = nums[j];
            }
        }
        return maxDifference;
    }
};