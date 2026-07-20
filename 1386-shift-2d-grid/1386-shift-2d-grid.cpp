// Array Rotating right shift k times trick=>
// 1. reverse(0,n-1)
// 2. reverse(0,k-1)
// 3. reverse(k,n-1)

// if a value is in i index of a 1d array then,
//  the row value & column value of it in the 2d array will be=> row = i/col &
//  col= i%col.
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size(), col = grid[0].size();
        int n = row * col;

        k = k % n;
        if (k == 0)
            return grid;

        auto reverse = [&](int i, int j) {
            while (i < j) {
                swap(grid[i / col][i % col], grid[j / col][j % col]);
                i++;
                j--;
            }
        };

        reverse(0, n - 1);
        reverse(0, k - 1);
        reverse(k, n - 1);

        return grid;
    }
};