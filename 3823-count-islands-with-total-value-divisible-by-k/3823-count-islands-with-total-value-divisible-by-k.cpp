class Solution {
public:
    using VB = vector<int>;
    using VBB = vector<VB>;
    int m, n;

    VBB directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    long dfs(int i, int j, VBB& grid) {
        long sum = grid[i][j];
        grid[i][j] = 0; // marked as visited

        for (VB& dir : directions) {
            int i_ = i + dir[0], j_ = j + dir[1];
            if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_] > 0)
                sum += dfs(i_, j_, grid);
        }

        return sum;
    }
    int countIslands(VBB& grid, int k) {
        m = grid.size(), n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    long sum = dfs(i, j, grid);
                    if (sum % k == 0)
                        count++;
                }
            }
        }

        return count;
    }
};