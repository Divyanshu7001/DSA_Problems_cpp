class Solution {
public:
    void markGuarded(int row, int col, vector<vector<int>>& grid) {

        // Up
        for (int i = row - 1; i >= 0; i--) {
            if (grid[i][col] == 2 || grid[i][col] == 3)
                break;
            grid[i][col] = 1;
        }

        // Down
        for (int i = row + 1; i < grid.size(); i++) {
            if (grid[i][col] == 2 || grid[i][col] == 3)
                break;
            grid[i][col] = 1;
        }

        // Left
        for (int j = col - 1; j >= 0; j--) {
            if (grid[row][j] == 2 || grid[row][j] == 3)
                break;
            grid[row][j] = 1;
        }

        // Right
        for (int j = col + 1; j < grid[0].size(); j++) {
            if (grid[row][j] == 2 || grid[row][j] == 3)
                break;
            grid[row][j] = 1;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {

        vector<vector<int>> grid(m, vector<int>(n, 0));

        // marking guard positions
        for (vector<int>& vec : guards) {
            int i = vec[0], j = vec[1];
            grid[i][j] = 2; // guard
        }

        for (vector<int>& vec : walls) {
            int i = vec[0], j = vec[1];
            grid[i][j] = 3; // walls
        }

        for (vector<int>& guard : guards) {
            int i = guard[0], j = guard[1];
            markGuarded(i, j, grid); // check directions and mark guarded
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    count++;
            }
        }

        return count;
    }
};