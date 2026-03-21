class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x,
                                         int y, int k) {

        for (int i = x, row = x + k - 1; i <= grid.size() - 1; i++, row--) {
            if (i > row)
                break;
            for (int j = y; j < y + k; j++)
                swap(grid[i][j], grid[row][j]);
        }
        return grid;
    }
};