#define ll long long
class Solution {
public:
    ll countCommas(long long n) {

        ll result = 0;
        ll lower = 1000, commas = 1;

        while (lower <= n) {
            ll upper = lower * 1000 - 1;
            if (upper > n)
                upper = n;

            ll countNos = upper - lower + 1;
            result += (countNos * commas);

            lower *= 1000;
            commas++;
        }
        return result;
    }
};