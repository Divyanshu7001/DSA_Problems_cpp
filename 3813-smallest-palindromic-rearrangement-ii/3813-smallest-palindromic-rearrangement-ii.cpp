class Solution {
public:
    long long nCr(int n, int r, int k) {
        // 5c3=5c2..holds property
        r = min(r, n - r);
        long long result = 1;
        for (int i = 1; i <= r; i++) {
            result = result * (n - r + i) / i;

            if (result >= k)
                return k;
        }
        return result;
    }

    string smallestPalindrome(string s, int k) {

        int n = s.length();

        char mid = ' ';
        if (n % 2 == 1) {
            mid = s[n / 2];
        }

        vector<int> count(26, 0);
        for (int i = 0; i < n; i++) {
            if (n % 2 == 1 && i == n / 2)
                continue; // skipping mid index as already reserved
            count[s[i] - 'a']++;
        }

        // We have to only build half string and then gonna add mid character &
        // then double it reducing the count frequencies to half for now
        for (int i = 0; i < 26; i++)
            count[i] /= 2;

        string halfResult = "";
        int half = n / 2;

        for (int i = 0; i < half; i++) {
            bool placedCharacter = false;
            for (int j = 0; j < 26;
                 j++) { // deciding which character to take and put
                if (count[j] > 0) {
                    count[j] -= 1; // supposing that we have taken this letter
                                   // in the first index

                    // count number of ways to fill the other position
                    // characters
                    long long ways = 1;
                    int letters = 0; // other than the fixed character..how many
                                     // more remains
                    for (int c = 0; c < 26; c++) {
                        letters += count[c];
                    }

                    for (int c = 0; c < 26; c++) {
                        if (count[c] > 0) {
                            ways *= nCr(letters, count[c], k);
                            letters -= count[c];
                        }

                        if (ways >= k)
                            break;
                    }

                    if (ways >=
                        k) { // this block contains the kth one(result string)
                        halfResult.push_back(
                            j + 'a'); // fixed this character in ith position

                        placedCharacter = true;
                        break;
                    }
                    k -= ways; // when k>=ways;
                    count[j] += 1;
                }
            }
            if (placedCharacter == false)
                return "";
        }

        string rev = halfResult;
        reverse(rev.begin(), rev.end());
        if (mid != ' ')
            halfResult.push_back(mid);

        return halfResult + rev;
    }
};