class Solution {
public:
    int getSum(const vector<int>& prefix, int l, int r) {
        if (l > r) return 0;
        if (l == 0) return prefix[r];
        return prefix[r] - prefix[l - 1];
    }

    int minCost(vector<int>& startPos, vector<int>& homePos,
                vector<int>& rowCosts, vector<int>& colCosts) {

        int m = rowCosts.size();
        int n = colCosts.size();

        vector<int> rowPrefix(m), colPrefix(n);

        rowPrefix[0] = rowCosts[0];
        for (int i = 1; i < m; i++)
            rowPrefix[i] = rowPrefix[i - 1] + rowCosts[i];

        colPrefix[0] = colCosts[0];
        for (int i = 1; i < n; i++)
            colPrefix[i] = colPrefix[i - 1] + colCosts[i];

        int sr = startPos[0];
        int sc = startPos[1];
        int hr = homePos[0];
        int hc = homePos[1];

        int ans = 0;

        // Vertical movement
        if (sr < hr)
            ans += getSum(rowPrefix, sr + 1, hr);
        else
            ans += getSum(rowPrefix, hr, sr - 1);

        // Horizontal movement
        if (sc < hc)
            ans += getSum(colPrefix, sc + 1, hc);
        else
            ans += getSum(colPrefix, hc, sc - 1);

        return ans;
    }
};