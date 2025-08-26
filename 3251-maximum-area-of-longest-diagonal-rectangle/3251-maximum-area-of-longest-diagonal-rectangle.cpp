class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiagonal = -1, maxArea = 0;

        for (auto& dimension : dimensions) {
            int diag =
                dimension[0] * dimension[0] + dimension[1] * dimension[1];
            int area = dimension[0] * dimension[1];

            if (diag > maxDiagonal || (diag == maxDiagonal && area > maxArea)) {
                maxDiagonal = diag;
                maxArea = area;
            }
        }

        return maxArea;
    }
};
