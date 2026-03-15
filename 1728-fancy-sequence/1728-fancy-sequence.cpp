class Fancy {
public:
    typedef long long ll;

    ll M = 1e9 + 7;

    vector<ll> seq;
    ll add = 0;
    ll mult = 1;

    // Binary Exponentiation for Fermat's Little Theorem -> power(mult, M-2);
    long long power(long long a, long long b) {
        if (b == 0)
            return 1;

        long long half = power(a, b / 2);
        long long result = (half * half) % M;

        if (b % 2 == 1) {
            result = (result * a) % M;
        }

        return result;
    }

    Fancy() {}

    void append(int val) {
        long long x = ((val - add) % M + M) * power(mult, M - 2) % M;
        seq.push_back(x);
    }

    void addAll(int inc) { add = (add + inc) % M; }

    void multAll(int m) {
        mult = (mult * m) % M;
        add = (add * m) % M;
    }

    int getIndex(int idx) {
        if (idx >= seq.size())
            return -1;

        return (seq[idx] * mult + add) % M;
    }
};

// TLE ...the addAll & multAll becomes o(n2) for worst case of 10^5 ..105 cases
// passed
//  class Fancy {
//  public:
//      const int M = 1e9 + 7;
//      vector<long long> nums;

//     Fancy() {}

//     void append(int val) {
//         nums.push_back(val % M);
//     }

//     void addAll(int inc) {
//         for (int i = 0; i < nums.size(); i++)
//             nums[i] = (nums[i] + inc) % M;
//     }

//     void multAll(int m) {
//         for (int i = 0; i < nums.size(); i++)
//             nums[i] = (nums[i] * 1LL * m) % M;
//     }

//     int getIndex(int idx) {
//         if (idx < 0 || idx >= nums.size())
//             return -1;
//         return nums[idx];
//     }
// };

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */