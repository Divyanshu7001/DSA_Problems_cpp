class Solution {
public:
    int bin_search(int low, int target, vector<int>& nums) {
        int res = -1,high = nums.size() - 1;
        //cout << "Target value: " <<target<< endl;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            //cout << "Mid " << nums[mid] << endl;
            if (nums[mid] >= target) {
                res = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return res;
    }

    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int res = INT_MIN;
        for (int i = 0; i < nums1.size(); i++) {
            int incIndex = bin_search(i, nums1[i], nums2);
            //cout << incIndex << endl;
            if (incIndex == -1)
                continue;
            res = max(res, incIndex - i);
        }
        return res == INT_MIN ? 0 : res;
    }
};