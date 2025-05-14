// Brute force
// Just like the part-1
// as the array of frequency is already given..so just go and iterate over to do
// the changes return the string length with mod

// not optimized for high transformation values
//  class Solution {
//  public:
//      int lengthAfterTransformations(string s, int t, vector<int>& nums) {
//          const int MOD = 1e9 + 7;

//         for (int i = 0; i < t; i++) {
//             string s_new = "";

//             for (char c : s) {
//                 int count = nums[c - 'a'];
//                 for (int j = 1; j <=count; j++) {
//                     char next_char = (c - 'a' + j) % 26 + 'a';
//                     s_new.push_back(next_char);
//                 }
//             }
//             s = move(s_new);
//         }
//         return s.length() % MOD;
//     }
// };

// Optimized 2D MATRIX Approach
#define ll long long
class Solution {
public:
    const int md = 1e9 + 7;
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        int n = s.size();
        vector<ll> fq(26);
        int SIZE = 26;
        for (int i = 0; i < n; i++) {
            fq[s[i] - 'a']++;
        };

        // Build the matrix
        // T(i,j)-> while expanding i j times, trnasformation forms (i+j)%26
        vector<vector<long long>> T(SIZE, vector<long long>(SIZE, 0));
        for (int i = 0; i < SIZE; i++) {
            for (int j = 1; j <= nums[i]; j++) {
                T[i][(i + j) % SIZE]++;
            }
        }
        // Matrix exponentiation
        auto Tt = binaryPower(T, t);

        // vector<long long> t_exp=multiPower(T,t,MOD);

        // frequency counting
        vector<ll> ufqs(SIZE, 0);
        // Multiply the matrix with frquency to get the updqted frquencies
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (fq[i] == 0)
                    continue;
                ufqs[j] = (ufqs[j] + (Tt[i][j] * fq[i]) % md) % md;
            }
        }
        ll ans = 0;
        for (int i = 0; i < SIZE; i++) {
            ans = (ans + ufqs[i]) % md;
        }

        return (int)ans;
    }

    vector<vector<long long>> binaryPower(vector<vector<long long>> t, ll exp) {
        vector<vector<long long>> res(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; i++) {
            res[i][i] = 1;
        }

        while (exp > 0) {
            if (exp & 1) {
                res = matmul(res, t);
            }
            t = matmul(t, t);
            exp >>= 1;
        }
        return res;
    }

    vector<vector<long long>> matmul(vector<vector<long long>>& A,
                                     vector<vector<long long>>& B) {
        vector<vector<long long>> res(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (A[i][j] == 0)
                    continue;
                for (int k = 0; k < 26; k++) {
                    res[i][k] = (res[i][k] + (A[i][j] * B[j][k]) % md) % md;
                }
            }
        }
        return res;
    }
};
