class Solution {
public:
    bool isBalance(int n) {
        vector<int> freq(10, 0);

        while (n > 0) {
            int digit = n % 10;
            freq[digit]++;
            n /= 10;
        }

        for (int digit = 0; digit < 10; digit++) {
            if (freq[digit] > 0 && freq[digit] != digit)
                return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        for (int i = n + 1; i <= 1224444; i++) {
            if (isBalance(i))
                return i;
        }
        return 0;
    }
};