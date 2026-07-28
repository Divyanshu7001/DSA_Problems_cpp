class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        if (n == 1)
            return s;

        sort(s.begin(), s.begin() + (n / 2));
        
        int i = 0;
        while (n > (n / 2)) {
            s[n - 1] = s[i];
            i++;
            n--;
        }
        return s;
    }
};