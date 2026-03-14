class Solution {
public:
    string solve(char initial, int startIndex, int targetIndex, int n) {

        string ans = "";
        ans.push_back(initial);

        int current = startIndex + 1;

        for (int pos = 2; pos <= n; pos++) {

            int remaining = n - pos + 1;
            int block = 1 << (remaining - 1);

            vector<char> options;

            for (char c : {'a','b','c'})
                if (c != ans.back())
                    options.push_back(c);

            if (targetIndex < current + block) {
                ans.push_back(options[0]);
            } else {
                ans.push_back(options[1]);
                current += block;
            }
        }

        return ans;
    }

    string getHappyString(int n, int k) {

        int total = 3 * (1 << (n - 1));
        if (k > total) return "";

        int division = total / 3;
        int start = 1;

        char initial;

        if (k <= division) {
            initial = 'a';
        } else if (k <= 2 * division) {
            initial = 'b';
            start = division + 1;
        } else {
            initial = 'c';
            start = 2 * division + 1;
        }

        return solve(initial, start - 1, k, n);
    }
};
