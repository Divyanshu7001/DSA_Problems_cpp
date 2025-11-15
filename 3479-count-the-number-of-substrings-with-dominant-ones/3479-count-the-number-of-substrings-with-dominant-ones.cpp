class Solution {
public:
    int numberOfSubstrings(string s) {

        int n = s.length();

        vector<int> CumCountOne(n, 0);
        CumCountOne[0] = (s[0] == '1') ? 1 : 0;

        for (int i = 1; i < n; i++) {
            CumCountOne[i] = CumCountOne[i - 1] + ((s[i] == '1') ? 1 : 0);
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int oneCount =
                    CumCountOne[j] - (i - 1 >= 0 ? CumCountOne[i - 1] : 0);
                int zeroCount = (j - i + 1) - oneCount;

                // Case-1: (0 count)^2>(1 count)
                if ((zeroCount * zeroCount) > oneCount) {
                    // skip j to avoid waste indices
                    int wasteIndices = (zeroCount * zeroCount) - oneCount;
                    j += wasteIndices - 1;
                    //-1 have to do as it does j++ in every
                    // iteration..so in this case -1 saves us
                } else if ((zeroCount * zeroCount) == oneCount) {
                    result += 1;
                } else { //(zeroCount*zeroCount)<oneCount
                    result += 1;

                    // now try to see how much extra j can jump while having
                    // valid substrings
                    int k = sqrt(oneCount) - zeroCount;
                    int next =
                        j + k; // next indice upto which the j can go safely

                    if (next >= n) {
                        result += (n - j - 1);
                        break; // every possible indice is safe..so we break
                               // early
                    } else
                        result += k;

                    j = next;
                }
            }
        }
        return result;
    }
};