// Linear DP (Bottom-Up)
// simple 1D array where `dp[i]`= longest valid parentheses substring length ending at index `i`.
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        if (n <= 1) return 0;

        vector<int> dp(n, 0);
        int maxLen = 0;

        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                // Case 1: "...()"
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                }
                // Case 2: "...))" -> need to match with corresponding '('
                else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + 2 + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0);
                }
                maxLen = max(maxLen, dp[i]);
            }
        }
        return maxLen;
    }
};


//MLE=> passed 228/235..
//cant set memo dp for 3*1e4 input..too large for both stack and heap
// class Solution {
// public:
//     int n;
//     //int t[30001][30001];
//     int solve(int start, int currIdx, int openCount, string s) {
//         if (currIdx >= n) {
//             return 0;
//         }

//         // if (t[currIdx][openCount] != -1)
//         //     return t[currIdx][openCount];

//         int open = 0, close = 0;
//         if (s[currIdx] == '(')
//             open = solve(start, currIdx + 1, openCount + 1, s);
//         else {
//             openCount--;
//             if (openCount < 0)
//                 return 0;
//             if (openCount == 0)
//                 close = max((currIdx - start + 1),
//                             solve(start, currIdx + 1, openCount, s));
//             else
//                 close = solve(start, currIdx + 1, openCount, s);
//         }

//         return max(open, close);
//     }
//     int longestValidParentheses(string s) {
//         n = s.length();

//         //memset(t, -1, sizeof(t));

//         if (n <= 1)
//             return 0;

//         int res = 0;
//         for (int i = 0; i < n - 1; i++) {
//             if (s[i] == '(')
//                 res = max(res, solve(i, i + 1, 1, s));
//         }

//         return res;
//     }
// };
