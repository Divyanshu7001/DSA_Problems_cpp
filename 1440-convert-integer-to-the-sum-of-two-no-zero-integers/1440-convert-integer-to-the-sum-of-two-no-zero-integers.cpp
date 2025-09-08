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
        vector<int> result = {-1, -1};
        for (int i = 0; i < n; i++) {
            if (!hasZero(i) && !hasZero(n - i)){
                result[0] = i;
                result[1] = n - i;
            }
        }
        return result;
    }
};