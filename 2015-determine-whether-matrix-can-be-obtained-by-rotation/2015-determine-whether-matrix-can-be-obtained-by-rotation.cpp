// 90degree rotate=>Transpose + row reverse
// 90degree anti-clock wise rotate=> Tranpose + col reverse

class Solution {
public:
    int n;
    void rotate(vector<vector<int>>& matrix) {
        // Transpose
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Revsere
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        n = mat.size();

        // After 4 rotations, it becomes same matrix again
        for (int c = 1; c <= 4; c++) {
            bool equal = true;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (mat[i][j] != target[i][j]) {
                        equal = false;
                        break;
                    }
                }
                if (!equal)
                    break;
            }
            if (equal)
                return true;
            rotate(mat);
        }
        return false;
    }
};