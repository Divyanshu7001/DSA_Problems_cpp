
class Solution {
public:
    int minInsertions(string s) {
        int res = 0;
        int need = 0;

        for (char c : s) {
            if (c == '(') {
                // If need is odd, insert one ')' first
                // to complete the previous pair.
                if (need % 2 == 1) {
                    res++;
                    need--;
                }

                need += 2;
            } else {
                need--;

                if (need < 0) {
                    // Insert '(' before this ')'.
                    res++;
                    need = 1;
                }
            }
        }

        return res + need;
    }
};
