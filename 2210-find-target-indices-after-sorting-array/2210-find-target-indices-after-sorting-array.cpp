class Solution {
public:
    int n;
    vector<int> solve(vector<int>& nums, int target) {
        int l = 0, r = n - 1;
        vector<int> res;
        for (int i = 0; i < n; i++)
            if (nums[i] == target)
                res.push_back(i);
        
        // while (l <= r) {
        //     int mid = l + (r - l) / 2;
        //     if (nums[mid] == target) {
        //         res.push_back(mid);
        //         l = mid + 1;
        //     } else if (nums[mid] < target) {
        //         l = mid + 1;
        //     } else
        //         r = mid - 1;
        // }
        return res;
    }
    vector<int> targetIndices(vector<int>& nums, int target) {
        n = nums.size();
        if (n == 1)
            return nums[0] == target ? vector<int>{0} : vector<int>{};
        sort(nums.begin(), nums.end());
        return solve(nums, target);
    }
};