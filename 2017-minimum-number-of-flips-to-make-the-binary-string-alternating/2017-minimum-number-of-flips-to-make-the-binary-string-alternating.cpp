class Solution {
public:
    int minFlips(string s) {

        int n = s.length();
        // Done for circular string problems to avoid shifting and making new
        // strings everytime(it holds every possible shifted states)
        s = (s + s);

        string s1, s2;
        // Alternated string creation
        for (int i = 0; i < 2 * n; i++) {
            s1 += (i % 2 ? '0' : '1');
            s2 += (i % 2 ? '1' : '0');
        }

        // Sliding window to get over the possible shifted strings and see the
        // efficient one
        int res = INT_MAX, flip1 = 0, flip2 = 0;

        int i = 0, j = 0;
        while (j < 2 * n) {
            if (s[j] != s1[j])
                flip1++;
            if (s[j] != s2[j])
                flip2++;

            if (j - i + 1 > n) { // time to shrink window(left shrink)
                if (s[i] != s1[i])
                    flip1--;
                if (s[i] != s2[i])
                    flip2--;
                i++;
            }

            if (j - i + 1 == n)
                res = min({res, flip1, flip2});
            j++;
        }
        return res;
    }
};