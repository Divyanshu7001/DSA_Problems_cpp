class Solution {
public:
    int n, MOD = 1e9 + 7;
    typedef pair<int,int>P;
    vector<vector<P>> t;

    bool isValid(int i, int j, vector<string>& board) {
        return i >= 0 && i < n && j >= 0 && j < n && board[i][j] != 'X';
    }

    void findScoreAndPaths(int i, int j, vector<string>& board, int& currScore,
                           int& currPaths, char ch, char side) {
        if (side == 'U') {
            i--;
        } else if (side == 'L') {
            j--;
        } else {
            i--;
            j--;
        }

        if (isValid(i, j, board)) { // UP
            auto [score, paths] = solve(i, j, board);
            currScore = score;
            currPaths = paths;

            if (currPaths > 0) {
                currScore += ch == 'S' ? 0 : ch - '0';
            }
        }
    }

    P solve(int i, int j, vector<string>& board) {

        if (board[i][j] == 'E')
            return make_pair(0, 1);

        if (board[i][j] == 'X')
            return t[i][j] = make_pair(0, 0);

        if (t[i][j] != make_pair(-1, -1))
            return t[i][j];

        int upScore = 0, upPaths = 0;
        int leftScore = 0, leftPaths = 0;
        int diagScore = 0, diagPaths = 0;

        char ch = board[i][j];

        // UP calls
        findScoreAndPaths(i, j, board, upScore, upPaths, ch, 'U');
        // LEFT calls
        findScoreAndPaths(i, j, board, leftScore, leftPaths, ch, 'L');
        // DIAGONAL calls
        findScoreAndPaths(i, j, board, diagScore, diagPaths, ch, 'D');

        // Find Best One
        int bestScore = upScore, bestPaths = upPaths;
        if (upScore == leftScore && leftScore == diagScore) {
            bestScore = upScore;
            bestPaths = upPaths + leftPaths + diagPaths;
        } else if (upScore == leftScore) {
            bestScore = upScore;
            bestPaths = upPaths + leftPaths;
        } else if (leftScore == diagScore) {
            bestScore = leftScore;
            bestPaths = leftPaths + diagPaths;
        }

        if (upScore > bestScore ||
            (upScore > bestScore && upPaths > bestPaths)) {
            bestScore = upScore;
            bestPaths = upPaths;
        }
        if (leftScore > bestScore ||
            (leftScore == bestScore && leftPaths > bestPaths)) {
            bestScore = leftScore;
            bestPaths = leftPaths;
        }

        if (diagScore > bestScore ||
            (diagScore == bestScore && diagPaths > bestPaths)) {
            bestScore = diagScore;
            bestPaths = diagPaths;
        }

        return t[i][j] = make_pair(bestScore, bestPaths % MOD);
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        t.assign(n, vector<P>(n, {-1, -1}));
        P res = solve(n - 1, n - 1, board);

        return {res.first, res.second};
    }
};