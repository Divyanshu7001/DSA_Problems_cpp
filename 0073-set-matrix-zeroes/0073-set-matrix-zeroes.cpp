// Brute force
// Make a new matrix2
// copy first matrix to mtrix 2
// keep iterating over the first matrix and update the matrix 2 accordingly
// At last copy the matrix 2 to matrix 1
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(),m = matrix[0].size();
        vector<vector<int>> matrix2=matrix;;

        // update the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    for (int k = 0; k < m; k++) {
                        matrix2[i][k] = 0;
                    }
                    for (int k = 0; k < n; k++) {
                        matrix2[k][j] = 0;
                    }
                }
            }
        }

        //copy
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                matrix[i][j] = matrix2[i][j];
            }
        }

    }
};