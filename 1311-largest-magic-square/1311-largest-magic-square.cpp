// Prefix sum approach => store every full row's sum & store every full column's
// sum
class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();

        // Row wise prefix sum
        vector<vector<int>> rowCumSum(rows, vector<int>(cols));
        for (int i = 0; i < rows; i++) {
            rowCumSum[i][0] = grid[i][0];
            for (int j = 1; j < cols; j++)
                rowCumSum[i][j] = rowCumSum[i][j - 1] + grid[i][j];
        }
        // Column wise prefix sum
        vector<vector<int>> colCumSum(rows, vector<int>(cols));
        for (int j = 0; j < cols; j++) {
            colCumSum[0][j] = grid[0][j];
            for (int i = 1; i < rows; i++) {
                colCumSum[i][j] = colCumSum[i - 1][j] + grid[i][j];
            }
        }

        // try all possible squares from each cell
        for (int side = min(rows, cols); side >= 2; side--) {
            for (int i = 0; i + side - 1 < rows; i++) {
                for (int j = 0; j + side - 1 < cols; j++) {
                    int targetSum = rowCumSum[i][j + side - 1] -
                                    (j > 0 ? rowCumSum[i][j - 1] : 0);
                    bool allSame = true;

                    // check rows
                    for (int r = i + 1; r < i + side; r++) {
                        int rowSum = rowCumSum[r][j + side - 1] -
                                     (j > 0 ? rowCumSum[r][j - 1] : 0);
                        if (rowSum != targetSum) {
                            allSame = false;
                            break;
                        }
                    }

                    if (!allSame)
                        continue;

                    // check cols
                    for (int c = j; c < j + side; c++) {
                        int colSum = colCumSum[i + side - 1][c] -
                                     (i > 0 ? colCumSum[i - 1][c] : 0);
                        if (colSum != targetSum) {
                            allSame = false;
                            break;
                        }
                    }

                    if (!allSame)
                        continue;

                    // Diagonal & Anti-diagonal check
                    int diagonal = 0, antiDiagonal = 0;
                    for (int k = 0; k < side; k++) {
                        diagonal += grid[i + k][j + k];
                        antiDiagonal += grid[i + k][j + side - 1 - k];
                    }

                    if (diagonal == targetSum && antiDiagonal == targetSum)
                        return side;
                }
            }
        }

        return 1;
    }
};

// Brute Force
// T.C=O(M*N*min(M,N)^3)=>O(n^5)
//  class Solution {
//  public:
//      bool solve(int startRow, int endRow, int startCol, int endCol,
//                 vector<vector<int>>& grid) {
//          int globalSum = 0;
//          for (int j = startCol; j <= endCol; j++)
//              globalSum += grid[startRow][j];

//         // row sum
//         for (int i = startRow + 1; i <= endRow; i++) {
//             int localSum = 0;
//             for (int j = startCol; j <= endCol; j++)
//                 localSum += grid[i][j];
//             if (localSum != globalSum)
//                 return false;
//         }

//         // col-wise sum
//         int col = startCol;
//         while (col <= endCol) {
//             int sum = 0;
//             for (int i = startRow; i <= endRow; i++)
//                 sum += grid[i][col];

//             if (sum != globalSum)
//                 return false;
//             col++;
//         }

//         // Left-diagonal sum
//         int leftDiagonal = 0, row = startRow;
//         col = startCol;
//         while (row <= endRow) {
//             leftDiagonal += grid[row][col];
//             row++;
//             col++;
//         }
//         if (leftDiagonal != globalSum)
//             return false;

//         // right-diagonal sum
//         int rightDiagonal = 0;
//         row = startRow;
//         col = endCol;
//         while (row <= endRow) {
//             rightDiagonal += grid[row][col];
//             row++;
//             col--;
//         }
//         if (rightDiagonal != globalSum)
//             return false;

//         return true;
//     }

//     int largestMagicSquare(vector<vector<int>>& grid) {

//         int m = grid.size(), n = grid[0].size();
//         int sz = min(m, n);

//         while (sz > 1) {
//             for (int i = 0; i <= m - sz; i++) {
//                 for (int j = 0; j <= n - sz; j++)
//                     if (solve(i, i + sz - 1, j, j + sz - 1, grid))
//                         return sz;
//             }
//             sz--;
//         }

//         return 1;
//     }
// };