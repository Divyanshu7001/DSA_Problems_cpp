class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int a = 0, b = 0, l = min(x, y), r = 0;

        for (char ch : s) {
            if (ch > 'b') {
                r += min(a, b) * l;
                a = 0;
                b = 0;
            } else if (ch == 'a') {
                if (x < y && b > 0) {
                    b--;
                    r += y;
                } else
                    a++;
            } else {
                if (x > y && a > 0) {
                    a--;
                    r += x;
                } else
                    b++;
            }
        }
        r += min(a, b) * l;
        return r;
    }
};