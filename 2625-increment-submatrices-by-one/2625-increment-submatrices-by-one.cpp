class Solution {
public:
    int N;
    vector<vector<int>> result;

    void solve(vector<int> LeftIndex, vector<int> RightIndex) {
        int RowStart = LeftIndex[0], RowEnd = RightIndex[0];
        int ColStart = LeftIndex[1], ColEnd = RightIndex[1];

        for (int i = RowStart; i <= RowEnd; i++) {
            for (int j = ColStart; j <= ColEnd; j++) {
                result[i][j] += 1;
            }
        }
    }

    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        N = n;
        result = vector<vector<int>>(N, vector<int>(N, 0));

        for (vector<int>& query : queries) {
            solve({query[0], query[1]}, {query[2], query[3]});
        }

        return result;
    }
};
