class Solution {
public:
    vector<int> pref;
    int t[501][501];
    int solve(int l, int r) {
        if (l >= r)
            return 0;
        if (t[l][r] != -1)
            return t[l][r];

        int score;
        for (int i = l; i < r; i++) {

            int leftSum = pref[i] - ((l - 1) >= 0 ? pref[l - 1] : 0);
            int rightSum = pref[r] - pref[i];

            if (leftSum < rightSum) {
                score = max(score, leftSum + solve(l, i));
            } else if (leftSum > rightSum) {
                score = max(score, rightSum + solve(i+1, r));
            } else { // leftSum==rightSum
                score =
                    max({score, leftSum + solve(l, i), rightSum + solve(i+1, r)});
            }
        }
        return t[l][r] = score;
    }
    int stoneGameV(vector<int>& stoneValue) {

        int n = stoneValue.size();
        pref.resize(n, 0);
        pref[0] = stoneValue[0];
        for (int i = 1; i < n; i++)
            pref[i] = pref[i - 1] + stoneValue[i];

        memset(t, -1, sizeof(t));

        return solve(0, n - 1);
    }
};