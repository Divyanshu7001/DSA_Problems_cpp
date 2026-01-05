class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {

        long long sum = 0;
        int negativeCount = 0, smallestNum = INT_MAX;
        bool isZeroPresent = false;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                int num = matrix[i][j];
                if (num < 0) {
                    negativeCount++;
                } else if (num == 0)
                    isZeroPresent = true;
                
                smallestNum = min(smallestNum, abs(num));
                sum += abs(num);
            }
        }

        if (negativeCount % 2 == 0)
            return sum;

        return isZeroPresent == true ? sum : sum - 2 * smallestNum;
    }
};