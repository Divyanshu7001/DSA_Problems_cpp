class Solution {
public:
    int M, N;
    int t[101][101];

    int solve(int i, int j) {
        // If we go out of bounds, return 0 paths
        if (i > M || j > N)
            return 0;
            
        if (i == M && j == N)
            return 1;

        if (t[i][j] != -1)
            return t[i][j];

        int right = solve(i, j + 1);
        int down = solve(i + 1, j);

        return t[i][j] = right + down;
    }

    int uniquePaths(int m, int n) {
        M = m - 1;
        N = n - 1;
        memset(t, -1, sizeof(t));
        return solve(0, 0);
    }
};