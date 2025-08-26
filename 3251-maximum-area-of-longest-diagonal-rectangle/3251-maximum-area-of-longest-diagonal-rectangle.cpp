class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiagonal = -1, maxArea = 0;

        for (auto& dimension : dimensions) {
            int currentDiagonal =
                dimension[0] * dimension[0] + dimension[1] * dimension[1];
            int area = dimension[0] * dimension[1];

            if (currentDiagonal > maxDiagonal || (currentDiagonal == maxDiagonal && area > maxArea)) {
                maxDiagonal = currentDiagonal;
                maxArea = area;
            }
        }

        return maxArea;
    }
};
