class Solution {
public:
    int n;

    pair<int, int> getCord(int y) {
        int row = n - 1 - (y - 1) / n;
        int col = (y - 1) % n;

        // Zigzag adjustment
        if ((n % 2 == 1 && row % 2 == 1) || (n % 2 == 0 && row % 2 == 0)) {
            col = n - 1 - col;
        }

        return {row, col};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        queue<int> q;
        vector<bool> seen(n * n + 1, false);

        q.push(1);
        seen[1] = true;
        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int x = q.front();
                q.pop();

                if (x == n * n)
                    return steps;

                for (int j = 1; j <= 6; j++) {
                    int next = x + j;
                    if (next > n * n) break;

                    pair<int, int> coord = getCord(next);
                    int r = coord.first;
                    int c = coord.second;

                    int dest = board[r][c] == -1 ? next : board[r][c];
                    if (!seen[dest]) {
                        seen[dest] = true;
                        q.push(dest);
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};
