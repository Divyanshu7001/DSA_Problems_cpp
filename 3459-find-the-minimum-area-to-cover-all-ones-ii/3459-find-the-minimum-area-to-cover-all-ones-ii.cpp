class Solution {
public:
    int m, n;
    int minimumArea(int startRow, int endRow, int startCol, int endCol,
                    vector<vector<int>>& grid) {

        int minRow = grid.size(), maxRow = -1;
        int minCol = grid[0].size(), maxCol = -1;

        for (int i = startRow; i < endRow; i++) {
            for (int j = startCol; j < endCol; j++) {
                if (grid[i][j] == 1) {
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);

                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
            }
        }

        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }

    int solve(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int result = INT_MAX;

        for (int rowSplit = 1; rowSplit < m; rowSplit++) {
            for (int colSplit = 1; colSplit < n; colSplit++) {

                int top = minimumArea(0, rowSplit, 0, n, grid);
                int bottomLeft = minimumArea(rowSplit, m, 0, colSplit, grid);
                int bottomRight = minimumArea(rowSplit, m, colSplit, n, grid);

                result = min(result, top + bottomLeft + bottomRight);

                int topLeft = minimumArea(0, rowSplit, 0, colSplit, grid);
                int topRight = minimumArea(0, rowSplit, colSplit, n, grid);
                int bottom = minimumArea(rowSplit, m, 0, n, grid);

                result = min(result, topLeft + topRight + bottom);
            }
        }

        for (int split1 = 1; split1 < m; split1++) {
            for (int split2 = split1 + 1; split2 < m; split2++) {
                int top = minimumArea(0, split1, 0, n, grid);
                int middle = minimumArea(split1, split2, 0, n, grid);
                int bottom = minimumArea(split2, m, 0, n, grid);

                result = min(result, top + middle + bottom);
            }
        }

        return result;
    }

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid) {
        int rowSize = grid.size(), colSize = grid[0].size();

        vector<vector<int>> rotatedGrid(colSize, vector<int>(rowSize));

        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                rotatedGrid[j][m - i - 1] = grid[i][j];
            }
        }

        return rotatedGrid;
    }

    int minimumSum(vector<vector<int>>& grid) {

        int result = solve(grid);

        vector<vector<int>> rotatedGrid = rotateGrid(grid);

        result = min(result, solve(rotatedGrid));

        return result;
    }
};