class Solution {
public:
    bool hasZero(int i) {
        while (i > 0) {
            if (i % 10 == 0)
                return true;
            i /= 10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int> result;
        for (int i = 1; i < n; i++) {
            if (!hasZero(i) && !hasZero(n - i)) {
                result = {i, n - i};
                break;
            }
        }
        return result;
    }
};