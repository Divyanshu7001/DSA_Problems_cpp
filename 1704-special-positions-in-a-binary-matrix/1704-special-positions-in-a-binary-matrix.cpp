//Optimized prefix sum row and columns One count
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> rowCount(m+1, 0);
        vector<int> colCount(n+1, 0);
        // pre compute the count of 1
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1){
                    rowCount[i] +=1;
                    colCount[j] +=1;
                }
            }
        }
        // now traversing once again
        int total = 0;
        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(mat[row][col] == 1 && rowCount[row] <= 1 && colCount[col] <= 1){
                    total++;
                    
                }
            }
        }
        return total;
    }
};

//Full Traversal..no optimization
//T.C=O(MâNâ(M+N))
// class Solution {
// public:
//     int res = 0, rows, cols;

//     void check(vector<vector<int>>& mat, int rowToCheck, int colToCheck) {
//         int countOne = 0;
//         for (int j = 0; j < cols; j++) {
//             if (mat[rowToCheck][j] == 1)
//                 countOne++;
//             if (countOne == 2)
//                 return;
//         }
//         countOne = 0;
//         for (int i = 0; i < rows; i++) {
//             if (mat[i][colToCheck] == 1)
//                 countOne++;
//             if (countOne == 2)
//                 return;
//         }
//         res++;
//     }

//     int numSpecial(vector<vector<int>>& mat) {
//         rows = mat.size(), cols = mat[0].size();

//         for (int i = 0; i < rows; i++) {
//             for (int j = 0; j < cols; j++) {
//                 if (mat[i][j] == 1)
//                     check(mat, i, j);
//             }
//         }
//         return res;
//     }
// };