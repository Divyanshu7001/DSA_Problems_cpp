class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        if (n == 1)
            return s;

        vector<int> freq(26, 0);

        for (int i = 0; i < n; i++)
            freq[s[i] - 'a']++;

        int halfSize = n / 2;

        sort(s.begin(), s.begin() + halfSize);
        int i = 0;
        while (halfSize < n) {
            s[n - 1] = s[i];
            i++;
            n--;
        }

        // string res = "";
        // for (int i = 0; i < 26; i++) {
        //     if (freq[i] != 0) {
        //         int toAdd = (freq[i] == 1) ? 1 : (freq[i] / 2);
        //         if (res.length() < halfSize) {
        //             while (toAdd) {
        //                 res += i + 'a';
        //                 toAdd--;
        //                 freq[i]--;
        //             }
        //         } else
        //             break;
        //     }
        // }

        // for (int i = 25; i >= 0; i--) {
        //     if (freq[i] != 0) {
        //         if (res.length() != n) {
        //             while (freq[i]!=0) {
        //                 res += i + 'a';
        //                 freq[i]--;
        //             }
        //         } else
        //             break;
        //     }
        // }

        return s;
    }
};