// T.C = O(N)
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result(n);
        if (n % 2 == 0) {
            for (int i = 0, j = -1; i < n / 2; i++, j--) {
                result[i] = j;
            }
            for (int i = n / 2, j = 1; i < n; i++, j++) {
                result[i] = j;
            }
        } else {
            for (int i = 0, j = -1; i < (n - 1) / 2; i++, j--) {
                result[i] = j;
            }
            result[(n - 1) / 2] = 0;
            for (int i = ((n - 1) / 2) + 1, j = 1; i < n; i++, j++) {
                result[i] = j;
            }
        }
        return result;
    }
};