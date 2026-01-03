class Solution {
public:
    int M = 1e9 + 7;

    // states
    string states[12] = {"RYG", "RGY", "RYR", "RGR", "YRG", "YGR",
                         "YGY", "YRY", "GRY", "GYR", "GRG", "GYG"};

    vector<vector<int>> t;
    int solve(int n, int prev) {
        // Found one way to paint the entire grid
        if (n == 0)
            return 1;

        if (t[n][prev] != -1)
            return t[n][prev];
        int result = 0;
        string last = states[prev];

        for (int curr = 0; curr < 12; curr++) {
            if (curr == prev)
                continue;

            string currPat = states[curr];
            bool conflict = false;

            for (int col = 0; col < 3; col++) {
                if (last[col] == currPat[col]) {
                    conflict = true;
                    break;
                }
            }

            if (!conflict)
                result = (result + solve(n - 1, curr)) % M;
        }

        return t[n][prev] = result;
    }

    int numOfWays(int n) {

        int res = 0;
        t.resize(n, vector<int>(12, -1));

        for (int i = 0; i < 12; i++) {
            res = (res + solve(n - 1, i)) % M;
        }

        return res;
    }
};