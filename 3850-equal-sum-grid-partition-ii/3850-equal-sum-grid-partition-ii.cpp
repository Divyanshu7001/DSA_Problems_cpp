// With corner case checking
class Solution {
public:
    typedef long long ll;
    ll total = 0;

    bool checkHorCuts(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        unordered_set<ll> st;
        ll top = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                st.insert(grid[i][j]);
                top += grid[i][j];
            }
            ll bottom = total - top;
            ll diff = top - bottom;

            if (diff == 0)
                return true;

            if (diff == (ll)grid[0][0])
                return true;
            if (diff == (ll)grid[0][n - 1])
                return true;
            if (diff == (ll)grid[i][0])
                return true;

            if (i > 0 && n > 1 && st.count(diff))
                return true;
        }

        return false;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                total += grid[i][j];
        }

        // Horizontal Cuts checking
        if (checkHorCuts(grid))
            return true;

        reverse(grid.begin(), grid.end());

        if (checkHorCuts(grid))
            return true;

        // Vertical Cuts Checking
        // Transpose the original grid & then have to use the same function
        // again
        reverse(grid.begin(), grid.end()); // Original again

        vector<vector<int>> transposeGrid(n, vector<int>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                transposeGrid[j][i] = grid[i][j];
        }

        if (checkHorCuts(transposeGrid))
            return true;

        reverse(transposeGrid.begin(), transposeGrid.end());

        if (checkHorCuts(transposeGrid))
            return true;

        return false;
    }
};

// With DFS
//  class Solution {
//  public:
//      bool check(vector<vector<int>>& grid) {
//          int m = grid.size(), n = grid[0].size();

//         // Try horizontal cuts
//         for (int row = 1; row < m; ++row) {
//             vector<vector<int>> top(grid.begin(), grid.begin() + row);
//             vector<vector<int>> bottom(grid.begin() + row, grid.end());
//             if (checkPartition(top, bottom)) return true;
//         }

//         // Try vertical cuts
//         for (int col = 1; col < n; ++col) {
//             vector<vector<int>> left(m), right(m);
//             for (int i = 0; i < m; ++i) {
//                 left[i] = vector<int>(grid[i].begin(), grid[i].begin() +
//                 col); right[i] = vector<int>(grid[i].begin() + col,
//                 grid[i].end());
//             }
//             if (checkPartition(left, right)) return true;
//         }

//         return false;
//     }

//     int sum(const vector<vector<int>>& part) {
//         long long total = 0;
//         for (auto& row : part)
//             for (auto v : row) total += v;
//         return total;
//     }

//     bool isConnected(const vector<vector<int>>& part, int skipX = -1, int
//     skipY = -1) {
//         int m = part.size(), n = part[0].size();
//         vector<vector<bool>> vis(m, vector<bool>(n, false));
//         function<void(int, int)> dfs = [&](int x, int y) {
//             if (x < 0 || x >= m || y < 0 || y >= n || vis[x][y] || (x ==
//             skipX && y == skipY) || part[x][y] == -1) return; vis[x][y] =
//             true; dfs(x+1, y); dfs(x-1, y); dfs(x, y+1); dfs(x, y-1);
//         };

//         bool started = false;
//         for (int i = 0; i < m && !started; ++i)
//             for (int j = 0; j < n && !started; ++j)
//                 if (!(i == skipX && j == skipY) && part[i][j] != -1) {
//                     dfs(i, j);
//                     started = true;
//                 }

//         for (int i = 0; i < m; ++i)
//             for (int j = 0; j < n; ++j)
//                 if (!(i == skipX && j == skipY) && part[i][j] != -1 &&
//                 !vis[i][j])
//                     return false;
//         return true;
//     }

//     bool checkPartition(vector<vector<int>>& A, vector<vector<int>>& B) {
//         int sumA = sum(A), sumB = sum(B);
//         if (sumA == sumB) return true;

//         // Try discounting one cell from A
//         for (int i = 0; i < A.size(); ++i)
//             for (int j = 0; j < A[0].size(); ++j) {
//                 int v = A[i][j];
//                 if (sumA - v == sumB && isConnected(A, i, j))
//                     return true;
//             }

//         // Try discounting one cell from B
//         for (int i = 0; i < B.size(); ++i)
//             for (int j = 0; j < B[0].size(); ++j) {
//                 int v = B[i][j];
//                 if (sumB - v == sumA && isConnected(B, i, j))
//                     return true;
//             }

//         return false;
//     }

//     bool canPartitionGrid(vector<vector<int>>& grid) {
//         return check(grid);
//     }
// };