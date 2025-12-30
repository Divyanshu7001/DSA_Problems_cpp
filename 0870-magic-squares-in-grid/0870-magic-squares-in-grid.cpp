class Solution {
private:
    bool isMagicalSquare(vector<vector<int>>& grid, int rowIndex,
                         int colIndex) {
        unordered_set<int> st;
        for (int i = rowIndex; i < rowIndex + 3; i++) {
            for (int j = colIndex; j < colIndex + 3; j++) {
                int num = grid[i][j];
                if (num < 1 || num > 9 || st.count(num))
                    return false;

                st.insert(num);
            }
        }

        // row-wise sum
        for (int i = rowIndex; i < rowIndex + 3; i++) {
            int sum = 0;
            for (int j = colIndex; j < colIndex + 3; j++) {
                sum += grid[i][j];
            }
            if (sum != 15)
                return false;
        }

        // col-wise sum
        int col = colIndex;
        while (col < colIndex + 3) {
            int sum = 0;
            for (int i = rowIndex; i < rowIndex + 3; i++)
                sum += grid[i][col];

            if (sum != 15)
                return false;
            col++;
        }

        // Left-diagonal sum
        int leftDiagonal = 0, row = rowIndex;
        col = colIndex;
        while (row < rowIndex + 3) {
            leftDiagonal += grid[row][col];
            row++;
            col++;
        }
        if (leftDiagonal != 15)
            return false;

        // right-diagonal sum
        int rightDiagonal = 0;
        row = rowIndex;
        col = colIndex + 2;
        while (row < rowIndex + 3) {
            rightDiagonal += grid[row][col];
            row++;
            col--;
        }
        if (rightDiagonal != 15)
            return false;

        return true;
    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int count = 0;

        for (int i = 0; i <= rows - 3; i++) {
            for (int j = 0; j <= cols - 3; j++) {
                if (isMagicalSquare(grid, i, j))
                    count++;
            }
        }

        return count;
    }
};