class Solution {
public:
    
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int result = 0;
        for (int i = 0; i < n; i++) {
            //A -> Upper Left cornor point
            int x1=points[i][0],y1=points[i][1];

            //B -> Lower right cornor point
            for (int j = 0; j < n; j++) {
                if (i != j){
                    int x2=points[j][0],y2=points[j][1];
                    if(x1<=x2 && y1>=y2){
                        bool hasPointInside=false;
                        for(int k=0;k<n;k++){
                            if(k==i || k==j)continue;
                            int x3=points[k][0],y3=points[k][1];
                            if(x3>=x1 && x3<=x2 && y3<=y1 && y3>=y2){
                                hasPointInside=true;
                                break;
                            }
                        }
                        if(!hasPointInside)result++;
                    }
                }

            }
        }
        return result;
    }
};

// Brute force by me..T.C=O(N3)
// class Solution {
// public:
//     int n;
//     set<pair<int, int>> seen; // Avoid duplicates

//     int solve(int currentIndex, int checkIndex, vector<vector<int>>& points) {
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
//                     if ((gettingCheckedX >= min(currentIndexX, checkIndexX) &&
//                          gettingCheckedX <= max(currentIndexX, checkIndexX)) &&
//                         (gettingCheckedY >= min(currentIndexY, checkIndexY) &&
//                          gettingCheckedY <= max(currentIndexY, checkIndexY))) {
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
//                          gettingCheckedY > min(currentIndexY, checkIndexY))) {
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
//                          gettingCheckedX > min(currentIndexX, checkIndexX))) {
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
