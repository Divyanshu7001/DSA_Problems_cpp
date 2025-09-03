// With sorting approach
// Sorting approach -> for normal cases..sorting by x-axis in asc order is good
// For edge cases -> where x values are same...sort those points in desc order
// of y-axis as in case of x values same..we can get the vertical line concept
// but for that y should be in decreasing order

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
            // A -> Upper Left cornor point
            int x1 = points[i][0], y1 = points[i][1];

            // have a track of maximum y seen upto some point..if the current
            // point's y is greater than this y..the rectangle formed by this
            // and ith point will be isolated.
            int maxY = INT_MIN;

            // B -> Lower right cornor point
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

// Brute force without sorting at first..MIK
//  class Solution {
//  public:
//      int numberOfPairs(vector<vector<int>>& points) {
//          int n = points.size();
//          int result = 0;
//          for (int i = 0; i < n; i++) {
//              // A -> Upper Left cornor point
//              int x1 = points[i][0], y1 = points[i][1];

//             // B -> Lower right cornor point
//             for (int j = 0; j < n; j++) {
//                 if (i != j) {
//                     int x2 = points[j][0], y2 = points[j][1];
//                     if (x1 <= x2 && y1 >= y2) {
//                         bool hasPointInside = false;
//                         for (int k = 0; k < n; k++) {
//                             if (k == i || k == j)
//                                 continue;
//                             int x3 = points[k][0], y3 = points[k][1];
//                             if (x3 >= x1 && x3 <= x2 && y3 <= y1 && y3 >= y2)
//                             {
//                                 hasPointInside = true;
//                                 break;
//                             }
//                         }
//                         if (!hasPointInside)
//                             result++;
//                     }
//                 }
//             }
//         }
//         return result;
//     }
// };

// Brute force by me..T.C=O(N3)
// class Solution {
// public:
//     int n;
//     set<pair<int, int>> seen; // Avoid duplicates

//     int solve(int currentIndex, int checkIndex, vector<vector<int>>& points)
//     {
//         int currentIndexX = points[currentIndex][0],
//             currentIndexY = points[currentIndex][1];

//         int checkIndexX = points[checkIndex][0],
//             checkIndexY = points[checkIndex][1];

//         // normalize pair
//         int a = min(currentIndex, checkIndex);
//         int b = max(currentIndex, checkIndex);

//         // if already counted, skip
//         if (seen.count({a, b}))
//             return 0;

//         // diagonal case (upper-left & bottom-right)
//         if ((currentIndexX > checkIndexX && currentIndexY < checkIndexY) ||
//             (currentIndexX < checkIndexX && currentIndexY > checkIndexY)) {

//             for (int i = 0; i < n; i++) {
//                 if (i != currentIndex && i != checkIndex) {
//                     int gettingCheckedX = points[i][0],
//                         gettingCheckedY = points[i][1];
//                     // strictly inside rectangle
//                     if ((gettingCheckedX >= min(currentIndexX, checkIndexX)
//                     &&
//                          gettingCheckedX <= max(currentIndexX, checkIndexX))
//                          &&
//                         (gettingCheckedY >= min(currentIndexY, checkIndexY)
//                         &&
//                          gettingCheckedY <= max(currentIndexY, checkIndexY)))
//                          {
//                         return 0;
//                     }
//                 }
//             }
//             seen.insert({a, b});
//             return 1;

//         } else if (currentIndexX == checkIndexX) { // vertical alignment
//             for (int i = 0; i < n; i++) {
//                 if (i != currentIndex && i != checkIndex) {
//                     int gettingCheckedY = points[i][1];
//                     if ((gettingCheckedY < max(currentIndexY, checkIndexY) &&
//                          gettingCheckedY > min(currentIndexY, checkIndexY)))
//                          {
//                         if (points[i][0] == currentIndexX)
//                             return 0;
//                     }
//                 }
//             }
//             seen.insert({a, b});
//             return 1;

//         } else if (currentIndexY == checkIndexY) { // horizontal alignment
//             for (int i = 0; i < n; i++) {
//                 if (i != currentIndex && i != checkIndex) {
//                     int gettingCheckedX = points[i][0];
//                     if ((gettingCheckedX < max(currentIndexX, checkIndexX) &&
//                          gettingCheckedX > min(currentIndexX, checkIndexX)))
//                          {
//                         if (points[i][1] == currentIndexY)
//                             return 0;
//                     }
//                 }
//             }
//             seen.insert({a, b});
//             return 1;
//         }

//         return 0;
//     }

//     int numberOfPairs(vector<vector<int>>& points) {
//         n = points.size();
//         int result = 0;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (i != j)
//                     result += solve(i, j, points);
//             }
//         }
//         return result;
//     }
// };
