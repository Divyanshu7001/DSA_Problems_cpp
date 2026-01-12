class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {

        int res = 0;

        for (int i = 0; i < points.size() - 1; i++) {
            int currentX = points[i][0], currentY = points[i][1];
            int nextX = points[i + 1][0], nextY = points[i + 1][1];

            int diffX = abs(nextX - currentX), diffY = abs(nextY - currentY);
            if (diffY >= diffX)
                res += diffY;
            else
                res += diffX;
        }

        return res;
    }
};