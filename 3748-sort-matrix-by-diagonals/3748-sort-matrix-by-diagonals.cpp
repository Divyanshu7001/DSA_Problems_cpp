class Solution {
public:
    int n;

    void solve(int row, int column, vector<vector<int>>& grid,
               bool isIncreasingSorting) {

        vector<int> tempList;
        int i = row, j = column;
        while (i < n && j < n) {
            tempList.push_back(grid[i][j]);
            i++;
            j++;
        }
        isIncreasingSorting == true
            ? sort(tempList.begin(), tempList.end())
            : sort(tempList.begin(), tempList.end(), greater<int>());
        i = row, j = column;
        for (int val : tempList) {
            grid[i][j] = val;
            i++;
            j++;
        }
    }

    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        n = grid.size();
        for (int j = 1; j < n - 1; j++) {
            solve(0, j, grid, true);
        }
        for (int i = 0; i < n - 1; i++) {
            solve(i, 0, grid, false);
        }

        return grid;
    }
};