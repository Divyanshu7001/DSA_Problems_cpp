// T.C = O(NâM)
//$ values are of changing parameters i.e row no, column no, direction & can
// turn or not
class Solution {
public:
    vector<vector<int>> directions = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int m, n, t[501][501][4][2];
    // 501,501 as row and column constraints , 4 for 4 kinds of direction
    // changes possible & 2 for the canTurn values true or false

    int solve(int i, int j, int d, bool canTurn, int val,
              vector<vector<int>>& grid) {
        int i_ = i + directions[d][0], j_ = j + directions[d][1];

        if (i_ < 0 || i_ >= n || j_ < 0 || j_ >= m || grid[i_][j_] != val) {
            return 0;
        }

        if (t[i_][j_][d][canTurn] != -1) {
            return t[i_][j_][d][canTurn];
        };

        int result = 0,
            keepMoving = 1 + solve(i_, j_, d, canTurn, val == 2 ? 0 : 2, grid);
        result = max(result, keepMoving);

        if (canTurn == true) {
            int turnAndMove =
                1 + solve(i_, j_, (d + 1) % 4, false, val == 2 ? 0 : 2, grid);
            result = max(result, turnAndMove);
        }

        return t[i_][j_][d][canTurn] = result;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(t, -1, sizeof(t));
        int res = 0;
        // start from every cell == 1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    for (int dir = 0; dir <= 3; dir++) {
                        res = max(res, 1 + solve(i, j, dir, true, 2, grid));
                    }
                }
            }
        }
        return res;
    }
};
