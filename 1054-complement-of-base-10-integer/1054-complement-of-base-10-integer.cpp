class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return 0;
        int counter = 0, res = 0;
        while (n) {
            int r = n % 2;
            res += pow(2, counter) * (!r);
            counter++;
            n = n / 2;
        }
        return res;
    }
};