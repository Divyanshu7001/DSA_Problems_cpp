//Binary Search => T.C=O(NlogM)
// class Solution {
// public:
//     int bin_search(int low, int target, vector<int>& nums) {
//         int res = -1,high = nums.size() - 1;
//         while (low <= high) {
//             int mid = low + (high - low) / 2;
//             if (nums[mid] >= target) {
//                 res = mid;
//                 low = mid + 1;
//             } else
//                 high = mid - 1;
//         }
//         return res;
//     }

//     int maxDistance(vector<int>& nums1, vector<int>& nums2) {
//         int res = INT_MIN;
//         for (int i = 0; i < nums1.size(); i++) {
//             int incIndex = bin_search(i, nums1[i], nums2);
//             if (incIndex == -1)
//                 continue;
//             res = max(res, incIndex - i);
//         }
//         return res == INT_MIN ? 0 : res;
//     }
// };


//Two Pointers => T.C=O(N+M)
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();
        int ans = 0;

        while (i < n && j < m) {
            if (nums1[i] <= nums2[j]) {
                ans = max(ans, j - i);
                j++;
            } else {
                i++;
                if (i > j) j = i;
            }
        }

        return ans;
    }
};