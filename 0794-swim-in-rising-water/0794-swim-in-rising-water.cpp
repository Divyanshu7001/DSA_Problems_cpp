class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        // Min-heap: (time, row, col)
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = 1;

        while (!pq.empty()) {
            auto [t, r, c] = pq.top();
            pq.pop();

            if (r == n - 1 && c == n - 1)
                return t; // reached destination

            for (auto [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nc >= 0 && nr < n && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = 1;
                    pq.push({max(t, grid[nr][nc]), nr, nc});
                }
            }
        }

        return -1; // should never happen

    }
};