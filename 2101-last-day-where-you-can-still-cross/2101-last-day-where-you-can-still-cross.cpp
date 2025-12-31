class Solution {
public:
    bool check(int day, int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> grid(row, vector<int>(col, 0));

        for (int i = 0; i < day; i++) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }

        vector<vector<int>> vis(row, vector<int>(col, 0));
        queue<pair<int, int>> q;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        // Start from top row
        for (int i = 0; i < col; i++) {
            if (grid[0][i] == 0) {
                q.push({0, i});
                vis[0][i] = 1;
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == row - 1)
                return true;

            for (int k = 0; k < 4; k++) {
                int nrow = r + dx[k];
                int ncol = c + dy[k];

                if (nrow >= 0 && nrow < row &&
                    ncol >= 0 && ncol < col &&
                    !vis[nrow][ncol] && grid[nrow][ncol] == 0) {

                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int low = 1, high = cells.size(), ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(mid, row, col, cells)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
