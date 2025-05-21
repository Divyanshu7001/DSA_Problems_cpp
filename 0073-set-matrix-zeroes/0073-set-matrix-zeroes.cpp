// Brute force
// Make a new matrix2
// copy first matrix to mtrix 2
// keep iterating over the first matrix and update the matrix 2 accordingly
// At last copy the matrix 2 to matrix 1

//But not changing in place
//so not the solution
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int n = matrix.size(),m = matrix[0].size();
//         vector<vector<int>> matrix2=matrix;;
//         // update the matrix
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (matrix[i][j] == 0) {
//                     for (int k = 0; k < m; k++) {
//                         matrix2[i][k] = 0;
//                     }
//                     for (int k = 0; k < n; k++) {
//                         matrix2[k][j] = 0;
//                     }
//                 }
//             }
//         }
//         //copy
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 matrix[i][j] = matrix2[i][j];
//             }
//         }
//     }
// };


//Optimized sol
//Take vectors according to size of m,n
//initialize at first with 1
//iterate over the matrix..if any 0s..update the vector cells
//at last..iterate over the vector and update the matrix accordingly
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(),n = matrix[0].size();
        vector<int> rowArray(m,1);
        vector<int> colArray(n,1);
        
        // update the Array
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    rowArray[i]=0;
                    colArray[j]=0;
                }
            }
        }

        //update the real matrix according to the row and column vector
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(rowArray[i]==0||colArray[j]==0){
                    matrix[i][j]=0;
                }
            }
        }
    }
};