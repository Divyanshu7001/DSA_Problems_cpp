class Solution {
public:
    int n;
    pair<int, int> getCord(int y) {
        int row = n - 1 - (y - 1) / n;
        int col = (y - 1) % n;

        if ((n % 2 == 1 && row % 2 == 1) || (n % 2 == 0 && row % 2 == 0)) {
            col = n - 1 - col;
        }

        return make_pair(row, col);
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        int steps = 0;
        queue<int> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[n - 1][0] = true;

        q.push(1);
        vector<bool> seen(n * n + 1, false);

        // bfs
        while (!q.empty()) {
            int N = q.size();
            while (N--) {
                int x = q.front();
                q.pop();

                if (x == n * n)
                    return steps;

                for (int j = 1; j <= 6; j++) {
                    if (x + j > n * n) {
                        break;
                    }

                    pair<int, int> coord = getCord(x + j);
                    int r = coord.first;
                    int c = coord.second;

                    if (visited[r][c] == true)
                        continue;

                    visited[r][c] = true;

                    if (board[r][c] == -1)
                        q.push(x + j);
                    else
                        q.push(board[r][c]);
                }
            }
            steps++;
        }
        return -1;
    }
};