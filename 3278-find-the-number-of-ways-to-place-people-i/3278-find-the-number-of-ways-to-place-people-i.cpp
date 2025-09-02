// class Solution {
// public:
//     int n;
//     set<pair<int, int>> seen; // Avoid duplicates

//     int solve(int currentIndex, int checkIndex, vector<vector<int>>& points)
//     {

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

// Brute force by me..failed
class Solution {
public:
    int n;
    set<pair<int, int>> seen; // Avoid duplicates

    int solve(int currentIndex, int checkIndex, vector<vector<int>>& points) {
        int currentIndexX = points[currentIndex][0],
            currentIndexY = points[currentIndex][1];

        int checkIndexX = points[checkIndex][0],
            checkIndexY = points[checkIndex][1];

        // normalize pair
        int a = min(currentIndex, checkIndex);
        int b = max(currentIndex, checkIndex);

        // if already counted, skip
        if (seen.count({a, b}))
            return 0;

        // diagonal case (upper-left & bottom-right)
        if ((currentIndexX > checkIndexX && currentIndexY < checkIndexY) ||
            (currentIndexX < checkIndexX && currentIndexY > checkIndexY)) {

            for (int i = 0; i < n; i++) {
                if (i != currentIndex && i != checkIndex) {
                    int gettingCheckedX = points[i][0],
                        gettingCheckedY = points[i][1];
                    // strictly inside rectangle
                    if ((gettingCheckedX >= min(currentIndexX, checkIndexX) &&
                         gettingCheckedX <= max(currentIndexX, checkIndexX)) &&
                        (gettingCheckedY >= min(currentIndexY, checkIndexY) &&
                         gettingCheckedY <= max(currentIndexY, checkIndexY))) {
                        return 0;
                    }
                }
            }
            seen.insert({a, b});
            cout << "returning from rectangle";
            return 1;

        } else if (currentIndexX == checkIndexX) { // vertical alignment
            for (int i = 0; i < n; i++) {
                if (i != currentIndex && i != checkIndex) {
                    int gettingCheckedY = points[i][1];
                    if ((gettingCheckedY < max(currentIndexY, checkIndexY) &&
                         gettingCheckedY > min(currentIndexY, checkIndexY))) {
                        if (points[i][0] == currentIndexX)
                            return 0;
                    }
                }
            }
            seen.insert({a, b});
            return 1;

        } else if (currentIndexY == checkIndexY) { // horizontal alignment
            cout << "in horizontal check" << "Current: " << currentIndex
                 << " checkedIndex: " << checkIndex << endl;
            for (int i = 0; i < n; i++) {
                if (i != currentIndex && i != checkIndex) {
                    int gettingCheckedX = points[i][0];
                    if ((gettingCheckedX < max(currentIndexX, checkIndexX) &&
                         gettingCheckedX > min(currentIndexX, checkIndexX))) {
                        if (points[i][1] == currentIndexY)
                            return 0;
                    }
                }
            }
            seen.insert({a, b});
            cout << "returning from horizontal";
            return 1;
        }

        return 0;
    }

    int numberOfPairs(vector<vector<int>>& points) {
        n = points.size();
        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j)
                    result += solve(i, j, points);
            }
        }
        return result;
    }
};
