class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        if (n == 1)
            return 1;

        long long res = 1;

        int prevDec = 1;
        for (int i = 1; i < n; i++) {
            if (prices[i - 1] - prices[i] == 1)
                prevDec++;
            else
                prevDec = 1;

            res += prevDec;
        }
        return res;
    }
};