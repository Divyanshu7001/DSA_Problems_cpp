class Solution {
public:
    int binarySearch(vector<int>& nums, int left, int right, int target) {
        int k = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < target) {
                k = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return k;
    }

    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return 0;
        sort(nums.begin(), nums.end());

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                continue;
            for (int j = i + 1; j < n; j++) {
                int position =
                    binarySearch(nums, j + 1, n - 1, nums[i] + nums[j]);
                if (position != -1)
                    count += (position - j);
            }
        }

        return count;
    }
};