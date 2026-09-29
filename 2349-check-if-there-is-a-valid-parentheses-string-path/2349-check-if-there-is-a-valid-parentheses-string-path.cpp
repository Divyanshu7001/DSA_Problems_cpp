class Solution {
public:
    int rows, cols;
    vector<vector<vector<int>>> t;
    int solve(int i, int j, int openCount, vector<vector<char>>& grid) {
        if (i >= rows || j >= cols)
            return 1;

        // process current cell
        if (grid[i][j] == '(')
            openCount++;
        else {
            if (openCount == 0)
                return 1;

            openCount--;
        }

        // check for last cell
        if (i == rows - 1 && j == cols - 1)
            return (openCount == 0) ? 0 : 1;

        if (t[i][j][openCount] != -1)
            return t[i][j][openCount];

        int down = solve(i + 1, j, openCount, grid);
        int right = solve(i, j + 1, openCount, grid);

        return t[i][j][openCount] = min(down, right);
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        if (grid[0][0] == ')')
            return false;

        rows = grid.size(), cols = grid[0].size();
        t.resize(rows, vector<vector<int>>(cols, vector<int>(rows + cols, -1)));

        // row_idx,col_idx,open_backet_count
        return solve(0, 0, 0, grid) == 0;
    }
};