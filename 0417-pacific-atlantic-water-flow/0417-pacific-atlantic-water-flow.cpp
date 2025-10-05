class Solution {
public:
    int m, n;
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(int r, int c, vector<vector<bool>>& visited,
             vector<vector<int>>& heights) {
        visited[r][c] = true;

        for (auto [dr, dc] : dirs) {
            int nr = r + dr, nc = c + dc;
            if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                continue;
            if (visited[nr][nc])
                continue;
            if (heights[nr][nc] < heights[r][c])
                continue; // must flow uphill
            dfs(nr, nc, visited, heights);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Start from Pacific (top + left)
        for (int i = 0; i < m; ++i)
            dfs(i, 0, pacific, heights);
        for (int j = 0; j < n; ++j)
            dfs(0, j, pacific, heights);

        // Start from Atlantic (bottom + right)
        for (int i = 0; i < m; ++i)
            dfs(i, n - 1, atlantic, heights);
        for (int j = 0; j < n; ++j)
            dfs(m - 1, j, atlantic, heights);

        // Collect cells reachable by both
        vector<vector<int>> res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};