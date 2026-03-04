//T.C=O(MâNâ(M+N))
class Solution {
public:
    int res = 0, rows, cols;

    void check(vector<vector<int>>& mat, int rowToCheck, int colToCheck) {
        int countOne = 0;
        for (int j = 0; j < cols; j++) {
            if (mat[rowToCheck][j] == 1)
                countOne++;
            if (countOne == 2)
                return;
        }
        countOne = 0;
        for (int i = 0; i < rows; i++) {
            if (mat[i][colToCheck] == 1)
                countOne++;
            if (countOne == 2)
                return;
        }
        res++;
    }

    int numSpecial(vector<vector<int>>& mat) {
        rows = mat.size(), cols = mat[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 1)
                    check(mat, i, j);
            }
        }
        return res;
    }
};