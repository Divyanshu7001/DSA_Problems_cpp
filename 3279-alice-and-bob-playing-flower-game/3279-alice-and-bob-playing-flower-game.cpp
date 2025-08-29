// Alice wins when total no. of flowers => ODD
// Total no. of ODD flowes taking technique:
// (ODD no. of first lane flowers + EVEN no. of second lane flowers) or (EVEN
// no. of first lane flowers + ODD no. of second lane flowers)
// Just return the multiplied probability of both chances

using LL = long long;

class Solution {
public:
    LL flowerGame(int n, int m) {
        return (((LL)(n + 1) / 2) * (m / 2)) + (((LL)n / 2) * ((m + 1) / 2));
    }
};
