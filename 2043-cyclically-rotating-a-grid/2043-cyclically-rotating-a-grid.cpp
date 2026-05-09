class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int layers = min(m, n) / 2;

        for (int layer = 0; layer < layers; layer++) {
            vector<int> nums;
            int top = layer, bottom = m - layer - 1;
            int left = layer, right = n - layer - 1;

            // Top row
            for (int j = left; j <= right; j++)
                nums.push_back(grid[top][j]);

            // Right column(top+1->bottom-1)
            for (int i = top + 1; i <= bottom - 1; i++)
                nums.push_back(grid[i][right]);

            // Bottom row
            for (int j = right; j >= left; j--)
                nums.push_back(grid[bottom][j]);

            // Left column(bottom->top)
            for (int i = bottom - 1; i >= top + 1; i--)
                nums.push_back(grid[i][left]);

            int len = nums.size();
            int normalized_k = k % len;

            rotate(begin(nums), begin(nums) + normalized_k, end(nums));

            int idx = 0;
            for (int j = left; j <= right; j++)
                grid[top][j] = nums[idx++];

            for (int i = top + 1; i <= bottom - 1; i++)
                grid[i][right] = nums[idx++];

            for (int j = right; j >= left; j--)
                grid[bottom][j] = nums[idx++];

            for (int i = bottom - 1; i >= top + 1; i--)
                grid[i][left] = nums[idx++];
        }
        return grid;
    }
};