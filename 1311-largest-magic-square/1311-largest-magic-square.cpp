class Solution {
public:
    bool solve(int startRow, int endRow, int startCol, int endCol,
               vector<vector<int>>& grid) {
        int globalSum = 0;
        for (int j = startCol; j <= endCol; j++)
            globalSum += grid[startRow][j];
        
        // row sum
        for (int i = startRow + 1; i <= endRow; i++) {
            int localSum = 0;
            for (int j = startCol; j <= endCol; j++)
                localSum += grid[i][j];
            if (localSum != globalSum)
                return false;
        }
       
        // col-wise sum
        int col = startCol;
        while (col <= endCol) {
            int sum = 0;
            for (int i = startRow; i <= endRow; i++)
                sum += grid[i][col];

            if (sum != globalSum)
                return false;
            col++;
        }
        
        // Left-diagonal sum
        int leftDiagonal = 0, row = startRow;
        col = startCol;
        while (row <= endRow) {
            leftDiagonal += grid[row][col];
            row++;
            col++;
        }
        if (leftDiagonal != globalSum)
            return false;
        
        // right-diagonal sum
        int rightDiagonal = 0;
        row = startRow;
        col = endCol;
        while (row <= endRow) {
            rightDiagonal += grid[row][col];
            row++;
            col--;
        }
        if (rightDiagonal != globalSum)
            return false;
        
        return true;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();
        int sz = min(m, n);

        while (sz > 1) {
            for (int i = 0; i <= m - sz; i++) {
                for (int j = 0; j <= n - sz; j++)
                    if (solve(i, i + sz - 1, j, j + sz - 1, grid))
                        return sz;
            }
            sz--;
        }

        return 1;
    }
};