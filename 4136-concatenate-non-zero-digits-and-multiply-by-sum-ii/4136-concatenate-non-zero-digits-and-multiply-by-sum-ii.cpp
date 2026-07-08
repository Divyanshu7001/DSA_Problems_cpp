class Solution {
public:
    typedef long long ll;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length(), MOD = 1e9 + 7;

        vector<int> nonZeroCount(n, 0);
        vector<ll> numberUpto(n, 0);
        vector<ll> digitSumUpto(n, 0);
        vector<ll> pow10(n + 1, 0); // 10^

        pow10[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        nonZeroCount[0] = s[0] != '0' ? 1 : 0;
        for (int i = 1; i < n; i++) {
            int dig = s[i] - '0';
            nonZeroCount[i] = nonZeroCount[i - 1] + (dig == 0 ? 0 : 1);
        }

        numberUpto[0] = s[0] - '0';
        for (int i = 1; i < n; i++) {
            int dig = s[i] - '0';
            if (dig != 0) {
                numberUpto[i] = (numberUpto[i - 1] * 10 + dig) % MOD;
            } else {
                numberUpto[i] = numberUpto[i - 1];
            }
        }

        digitSumUpto[0] = s[0] - '0';
        for (int i = 1; i < n; i++) {
            digitSumUpto[i] = digitSumUpto[i - 1] + (s[i] - '0');
        }

        vector<int> res;

        for (auto& query : queries) {
            int l = query[0], r = query[1];

            // sum*x
            ll sum = digitSumUpto[r] - ((l == 0) ? 0 : digitSumUpto[l - 1]);

            int numBefore = (l == 0) ? 0 : numberUpto[l - 1];
            int k = nonZeroCount[r] - ((l == 0) ? 0 : nonZeroCount[l - 1]);

            ll x =
                (numberUpto[r] - (numBefore * pow10[k] % MOD) + MOD) % MOD;

            res.push_back((int)((x * sum) % MOD));
        }
        return res;
    }
};

// class Solution {
// public:
//     vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
//         int n = s.length(), MOD = 1e9 + 7;
//         vector<pair<string, int>> pref(n, {"", -1});

//         string tmp = to_string(s[0]);
//         int sum = s[0] - '0';
//         pref[0] = make_pair(tmp, sum);

//         for (int i = 1; i < n; i++) {
//             if (s[i] == '0') {
//                 pref[i] = pref[i - 1];
//                 continue;
//             }
//             tmp += s[i];
//             sum += s[i] - '0';
//             pref[i] = make_pair(tmp, sum);
//         }

//         vector<int> res;
//         for (auto& query : queries) {
//             int start = query[0], end = query[1];

//             if (start == 0) {
//                 if (end < n) {
//                     cout << "here";
//                     res.push_back((stol(pref[end].first) * pref[end].second)
//                     %
//                                   MOD);
//                 }
//                 continue;
//             }

//             if (start == end) {
//                 res.push_back((s[end] - '0' * s[end] - '0') % MOD);
//                 continue;
//             }

//             int result =
//                 stol(pref[end].first.substr(pref[start - 1].first.length()));
//             int mul = pref[end].second - pref[start].second;
//             res.push_back((result * mul) % MOD);
//         }

//         return res;
//     }
// };