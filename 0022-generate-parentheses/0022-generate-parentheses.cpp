class Solution {
public:
    vector<string> res;
    int N;
    void solve(string curr, int openCount, int closeCount) {
        if (curr.length() == 2 * N) {
            res.push_back(curr);
            return;
        }
        if (openCount < N) {
            // take open
            // do
            curr.push_back('(');
            // explore
            solve(curr, openCount + 1, closeCount);
            // undo
            curr.pop_back();
        }
        if (closeCount < openCount) {
            curr.push_back(')');
            solve(curr, openCount, closeCount + 1);
        }
    }

    vector<string> generateParenthesis(int n) {
        if (n == 1)
            return vector<string>(1, "()");
        N = n;
        solve("(", 1, 0);

        return res;
    }
};