class Solution {
public:
    bool solve(vector<int>& nums, int i) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == i) {
                return true;
            } else if (i > nums[mid]) {
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return false;
    }

    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for (int& i : nums1)
            if (solve(nums2, i))
                return i;

        return -1;
    }
};