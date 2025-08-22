class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int minRow = m, maxRow = -1;
        int minCol = n, maxCol = -1;

        // Traverse the grid to locate all 1s
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);
                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
            }
        }

        // If no 1 found, area is 0 (depends on problem statement)
        if (maxRow == -1)
            return 0;

        int height = maxRow - minRow + 1;
        int width = maxCol - minCol + 1;
        return height * width;
    }
};