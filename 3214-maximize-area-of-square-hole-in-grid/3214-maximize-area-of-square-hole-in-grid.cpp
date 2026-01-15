class Solution {
public:
    int solve(vector<int>& bars) {
        int maxConsecutive = 1, currConsecutive = 1;
        for (int i = 1; i < bars.size(); i++) {
            if (bars[i] - bars[i - 1] == 1)
                currConsecutive++;
            else
                currConsecutive = 1;

            maxConsecutive = max(maxConsecutive, currConsecutive);
        }
        return maxConsecutive;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
                               vector<int>& vBars) {

        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int maxConsecutiveHbars = solve(hBars);
        int maxConsecutiveVbars = solve(vBars);

        return pow(min(maxConsecutiveHbars, maxConsecutiveVbars) + 1, 2);
    }
};