class Solution {
public:
    typedef pair<int, pair<int, int>>
        PP; // pair showing height , co-ordinate of the height
    vector<vector<int>> directions = {
        {0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // up,down,left & right
    int trapRainWater(vector<vector<int>>& heightMap) {

        int m = heightMap.size();
        int n = heightMap[0].size();

        priority_queue<PP, vector<PP>, greater<>>
            boundaryCells; // min-heap of <height,co-ordinate of the height
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Pushing boundary values in min-heap
        // left-most and right-most column(0,n-1)
        for (int row = 0; row < m; row++) {
            for (int col : {0, n - 1}) {
                boundaryCells.push({heightMap[row][col], {row, col}});
                visited[row][col] = true;
            }
        }

        // Top-most & bottom-most Column(0,n-1)
        for (int col = 0; col < n; col++) {
            for (int row : {0, m - 1}) {
                boundaryCells.push({heightMap[row][col], {row, col}});
                visited[row][col] = true;
            }
        }

        int water = 0;
        while (!boundaryCells.empty()) {
            PP p = boundaryCells.top();
            boundaryCells.pop();

            int height = p.first;
            int i = p.second.first;
            int j = p.second.second;

            // Explore neightbours
            for (vector<int>& dir : directions) {
                int i_ = i + dir[0], j_ = j + dir[1];

                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n &&
                    !visited[i_][j_]) {
                    water += max(height - heightMap[i_][j_], 0);
                    boundaryCells.push(
                        {max(height, heightMap[i_][j_]), {i_, j_}});
                    visited[i_][j_] = true;
                }
            }
        }
        return water;
    }
};