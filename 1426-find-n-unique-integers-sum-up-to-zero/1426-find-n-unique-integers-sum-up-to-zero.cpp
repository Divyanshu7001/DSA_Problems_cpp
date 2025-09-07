// T.C = O(N)
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result(n, -1);
        if (n % 2 == 0) {
            int current = -1;
            for (int i = 0; i < n / 2; i++) {
                result[i] = current;
                current--;
            }
            current = 1;
            for (int i = n / 2; i < n; i++) {
                result[i] = current;
                current++;
            }
        } else {
            int current = -1;
            for (int i = 0; i < (n - 1) / 2; i++) {
                result[i] = current;
                current--;
            }
            result[(n - 1) / 2] = 0;
            current = 1;
            for (int i = ((n - 1) / 2) + 1; i < n; i++) {
                result[i] = current;
                current++;
            }
        }

        return result;
    }
};