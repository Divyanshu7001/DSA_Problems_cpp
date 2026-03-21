class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x,
                                         int y, int k) {

        int row = x + k - 1;
        for (int i = x; i <= grid.size() - 1; i++) {
            if (row == 0 || i > row)
                break;
            for (int j = y; j < y + k; j++) {
                cout << "Swapping " << grid[i][j] << " & " << grid[row][j]
                     << endl;
                swap(grid[i][j], grid[row][j]);
            }

            row--;
        }
        return grid;
    }
};