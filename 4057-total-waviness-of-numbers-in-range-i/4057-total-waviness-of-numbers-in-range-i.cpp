class Solution {
public:
    int solve(int num) {
        string s = to_string(num);
        int n = s.length();
        if (n == 1 || n == 2)
            return 0;

        int wavi = 0;
        for (int i = 1; i < n - 1; i++) {
            if ((s[i] < s[i - 1] && s[i] < s[i + 1]) ||
                (s[i] > s[i - 1] && s[i] > s[i + 1]))
                wavi++;
        }

        return wavi;
    }

    int totalWaviness(int num1, int num2) {
        int res = 0;
        while (num1 <= num2) {
            res += solve(num1);
            num1++;
        }
        return res;
    }
};