class Solution {
public:
    int M = 1e9 + 7;
    int dp[2001];
    vector<int> prev;

    int solve(int n) {
        if (n == 0)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        int total = (2 * solve(n - 1)) % M;

        if (prev[n] != 0) {
            int duplicates = solve(prev[n] - 1);
            total = (total - duplicates + M) % M;
        }
        return dp[n] = total;
    }

    int distinctSubseqII(string s) {
        int n = s.length();
        memset(dp, -1, sizeof(dp));
        prev.assign(n + 1, 0); // n+1 because using 1 based indexing

        vector<int> lastSeen(26, 0);
        for (int i = 1; i <= n; i++) {
            int idx = s[i - 1] - 'a';
            prev[i] = lastSeen[idx];
            lastSeen[idx] = i;
        }
        return (solve(n) - 1 + M) % M;
    }
};

// TLE and memoization is complex for this one
//  class Solution {
//  public:
//      unordered_set<string> st;
//      int n;

//     void solve(string& s, string curr, int i, int len) {
//         if (curr.length() == len) {
//             //cout << curr << endl;
//             st.insert(curr);
//             if (i < n)
//                 solve(s, "", i, len);
//             return;
//         }
//         if (i == n)
//             return;

//         // skip
//         solve(s, curr, i + 1, len);

//         // take
//         curr.push_back(s[i]);
//         solve(s, curr, i + 1, len);
//     }

//     int distinctSubseqII(string s) {
//         n = s.length();
//         int i = 1;
//         while (i <= n) {
//             solve(s, "", 0, i);
//             i++;
//         }

//         return st.size();
//     }
// };