// Now as the size or side of square wanted as answer is monotonic
// increasing..so we can use binary search on side
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {

        int rows = mat.size(), cols = mat[0].size();

        vector<vector<int>> prefix(rows, vector<int>(cols, 0));
        // prefix[i][j]=sum of all elements from top left [0][0] to [i][j]

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                prefix[i][j] = (i > 0 ? prefix[i - 1][j] : 0) +
                               (j > 0 ? prefix[i][j - 1] : 0) -
                               ((i > 0 && j > 0) ? prefix[i - 1][j - 1] : 0) +
                               mat[i][j];
            }
        }

        auto sumSquare = [&](int i, int j, int r2, int c2) {
            int sum = prefix[r2][c2];

            if (i > 0)
                sum -= prefix[i - 1][c2];
            if (j > 0)
                sum -= prefix[r2][j - 1];
            if (i > 0 && j > 0)
                sum += prefix[i - 1][j - 1];

            return sum;
        };

        auto check =
            [&](int side) {
                for (int i = 0; i + side - 1 < rows; i++) {
                    for (int j = 0; j + side - 1 < cols; j++) {
                        int r2 = i + side - 1, c2 = j + side - 1;

                        if (sumSquare(i, j, r2, c2) <= threshold)
                            return true;
                    }
                }
                return false;
            };

        int low = 1,
             high = min(rows, cols), result = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid)) {
                result = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }

        return result;
    }
};

// prefix sum on 2d array with every cell having sum value from top left until
// that O(1) finding of a perticular sized matrix sum by the prefix sum we
// already have checking all the points with all the possible squares which can
// be made from that point
//  class Solution {
//  public:
//      int maxSideLength(vector<vector<int>>& mat, int threshold) {

//         int rows = mat.size(), cols = mat[0].size();

//         vector<vector<int>> prefix(rows, vector<int>(cols, 0));
//         // prefix[i][j]=sum of all elements from top left [0][0] to [i][j]

//         for (int i = 0; i < rows; i++) {
//             for (int j = 0; j < cols; j++) {
//                 prefix[i][j] = (i > 0 ? prefix[i - 1][j] : 0) +
//                                (j > 0 ? prefix[i][j - 1] : 0) -
//                                ((i > 0 && j > 0) ? prefix[i - 1][j - 1] : 0)
//                                + mat[i][j];
//             }
//         }

//         auto sumSquare = [&](int i, int j, int r2, int c2) {
//             int sum = prefix[r2][c2];

//             if (i > 0)
//                 sum -= prefix[i - 1][c2];
//             if (j > 0)
//                 sum -= prefix[r2][j - 1];
//             if (i > 0 && j > 0)
//                 sum += prefix[i - 1][j - 1];

//             return sum;
//         };

//         int best = 0;
//         for (int i = 0; i < rows; i++) {
//             for (int j = 0; j < cols; j++) {

//                 // offset loop => To check all the possible squares from a
//                 // perticular point

//                 // k=best=>if we get a size of 2 square with
//                 sum<=threshold,then
//                 // we should be looking for a better size one
//                 for (int k = best; k < min(rows - i, cols - j); k++) {
//                     int r2 = i + k, c2 = j + k;

//                     int sum = sumSquare(i, j, r2, c2);

//                     if (sum <= threshold)
//                         best = max(best, k + 1);
//                     else
//                         break;
//                 }
//             }
//         }

//         return best;
//     }
// };

// Brute Force=>TLE
//  class Solution {
//  public:
//      bool solve(int startRow, int endRow, int startCol, int endCol,
//                 vector<vector<int>>& mat, int threshold) {
//          int sum = 0;
//          for (int i = startRow; i <= endRow; i++) {
//              for (int j = startCol; j <= endCol; j++)
//                  sum += mat[i][j];
//          }

//         if (sum <= threshold)
//             return true;

//         return false;
//     }

//     int maxSideLength(vector<vector<int>>& mat, int threshold) {

//         int m = mat.size(), n = mat[0].size();
//         int sz = min(m, n);

//         while (sz > 1) {
//             for (int i = 0; i <= m - sz; i++) {
//                 for (int j = 0; j <= n - sz; j++)
//                     if (solve(i, i + sz - 1, j, j + sz - 1, mat, threshold))
//                         return sz;
//             }
//             sz--;
//         }

//         if (sz == 1) {
//             for (int i = 0; i < m; i++) {
//                 auto it = find(mat[i].begin(), mat[i].end(), threshold);
//                 if (it != mat[i].end())
//                     return 1;
//             }
//         }

//         return 0;
//     }
// };