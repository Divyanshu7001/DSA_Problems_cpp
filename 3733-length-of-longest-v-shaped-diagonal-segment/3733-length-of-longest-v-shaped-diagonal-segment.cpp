class Solution {
public:
    int n, m;
    vector<vector<int>> grid;

    // 4 diagonal directions: NW, NE, SE, SW
    int dx[4] = {-1, -1, 1, 1};
    int dy[4] = {-1, 1, 1, -1};

    // dp[row][col][dir][turnUsed][valIndex]
    // valIndex: 0 => expecting 2, 1 => expecting 0
    int dp[501][501][4][2][2];

    // convert expected value (2 or 0) to index
    int valToIdx(int v) {
        return (v == 2 ? 0 : 1);
    }

    // get clockwise direction
    int clockwise(int dir) {
        return (dir + 1) % 4;
    }

    // recursive solver
    int dfs(int i, int j, int dir, int turnUsed, int expectedVal) {
        if (i < 0 || j < 0 || i >= n || j >= m) return 0;
        if (grid[i][j] != expectedVal) return 0;

        int idx = valToIdx(expectedVal);
        int &ans = dp[i][j][dir][turnUsed][idx];
        if (ans != -1) return ans;

        int nextVal = (expectedVal == 2 ? 0 : 2);

        // continue straight
        int ni = i + dx[dir];
        int nj = j + dy[dir];
        int straight = dfs(ni, nj, dir, turnUsed, nextVal);

        // try turning (once)
        int turned = 0;
        if (!turnUsed) {
            int ndir = clockwise(dir);
            int ni2 = i + dx[ndir];
            int nj2 = j + dy[ndir];
            turned = dfs(ni2, nj2, ndir, 1, nextVal);
        }

        ans = 1 + max(straight, turned);
        return ans;
    }

    int lenOfVDiagonal(vector<vector<int>>& g) {
        grid = g;
        n = grid.size();
        m = grid[0].size();
        memset(dp, -1, sizeof(dp));

        int res = 0;
        // start from every cell == 1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    for (int dir = 0; dir < 4; dir++) {
                        int ni = i + dx[dir];
                        int nj = j + dy[dir];
                        res = max(res, 1 + dfs(ni, nj, dir, 0, 2));
                    }
                }
            }
        }
        return res;
    }
};
