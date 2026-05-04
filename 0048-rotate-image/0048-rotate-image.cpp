// Matrix 90 degree rotation -> Tranpose matrix & reverse each row horizontally
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        //Transpose
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);

        for (int i = 0; i < n; i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};