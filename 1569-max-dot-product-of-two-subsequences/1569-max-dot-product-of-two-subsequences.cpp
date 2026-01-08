class Solution {
public:
    int m, n;
    vector<vector<int>> t =
        vector<vector<int>>(501, vector<int>(501, -1e9));

    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j) {

        if (i == m || j == n)
            return -1e9;

        if (t[i][j] != -1e9)
            return t[i][j];
        int val = nums1[i] * nums2[j];
        int take_i_j =
            (nums1[i] * nums2[j]) + solve(nums1, nums2, i + 1, j + 1);
        int take_i = solve(nums1, nums2, i, j + 1);
        int take_j = solve(nums1, nums2, i + 1, j);

        return t[i][j] = max({val, take_i_j, take_i, take_j});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {

        m = nums1.size(), n = nums2.size();

        return solve(nums1, nums2, 0, 0);
    }
};