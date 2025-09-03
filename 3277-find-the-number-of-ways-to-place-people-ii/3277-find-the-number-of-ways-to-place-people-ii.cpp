// With sorting approach
// Sorting approach -> for normal cases..sorting by x-axis in asc order is good
// For edge cases -> where x values are same...sort those points in desc order
// of y-axis as in case of x values same..we can get the vertical line concept
// but for that y should be in decreasing order
//T.C=O(n2)
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int result = 0;

        auto lambda = [](vector<int>& points1, vector<int>& points2) {
            if (points1[0] == points2[0]) {
                return points1[1] > points2[1];
            }
            return points1[0] < points2[0];
        };

        sort(begin(points), end(points), lambda);
        for (int i = 0; i < n; i++) {
            // A -> Upper Left cornor point => Alice
            int x1 = points[i][0], y1 = points[i][1];

            // have a track of maximum y seen upto some point..if the current
            // point's y is greater than this y..the rectangle formed by this
            // and ith point will be isolated.
            int maxY = INT_MIN;

            // B -> Lower right cornor point => Bob
            for (int j = i + 1; j < n; j++) {

                int x2 = points[j][0], y2 = points[j][1];

                // If current point's y is greater than 1st point's y..cant take
                // it
                if (y2 > y1)
                    continue;

                if (y2 > maxY) {
                    result++;
                    maxY = y2;
                }
            }
        }
        return result;
    }
};