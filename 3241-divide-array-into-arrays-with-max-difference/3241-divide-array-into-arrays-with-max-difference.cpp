//T.C=O(NlogN)
//Hold in the map..loop through
//Push_back into result when satisfies the condition

// class Solution {
// public:
//     vector<vector<int>> divideArray(vector<int>& nums, int k) {
//         int n = nums.size();
//         int numberOfArrays = n / 3;
//         map<int, int> mp;
//         for (int num : nums) {
//             mp[num]++;
//         }

//         vector<vector<int>> result;

//         while (numberOfArrays > 0) {
//             vector<int> temp;
//             bool groupFormed = false;

//             for (auto pair = mp.begin(); pair != mp.end();) {
//                 if (temp.empty() ||
//                     (pair->first - temp.front() <= k && temp.size() < 3)) {
//                     temp.push_back(pair->first);
//                     pair->second--;
//                     if (pair->second == 0) {
//                         pair = mp.erase(pair);
//                     } 
//                     if (temp.size() == 3) {
//                         result.push_back(temp);
//                         numberOfArrays--;
//                         groupFormed = true;
//                         break;
//                     }
//                 } else {
//                     ++pair;
//                 }
//             }

//             if (!groupFormed) {
//                 return {};
//             }
//         }

//         return result;
//     }
// };

//T.C=O(NlogN)
//S.C=O(N)
//The difference between any two elements in one array is less than or equal to k.
//Used the above line as the main point of reference
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < nums.size(); i += 3) {
            int a = nums[i];
            int b = nums[i + 1];
            int c = nums[i + 2];

            // Check max difference in group
            if (c - a > k) {
                return {}; // invalid group
            }

            result.push_back({a, b, c});
        }

        return result;
    }
};
