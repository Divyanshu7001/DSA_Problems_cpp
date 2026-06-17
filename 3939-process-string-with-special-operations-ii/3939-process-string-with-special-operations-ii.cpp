// Two pass solution
// 1st pass=> process & find the total length(L)
// reverse process=> keep loooking..if after processing current...L==K, then
// return current character
//  if #->L=L/2 & if k>L ..then k=k-L/2
//  if %->L stays same & k = L-k-1
//  if *->L++ & k stays same
class Solution {
public:
    char processStr(string s, long long k) {

        int n = s.length();
        long long L = 0;

        for (char& ch : s) {
            if (ch == '*') {
                if (L > 0)
                    L--;
            } else if (ch == '#')
                L *= 2;
            else if (ch == '%')
                continue;
            else
                L++;
        }

        cout<<L;

        // Invalid k
        if (L == 0 || k >= L)
            return '.';

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '*')
                L++;
            else if (s[i] == '%')
                k = L - k - 1;
            else if (s[i] == '#') {
                L = L / 2;
                if (k >= L)
                    k = k - L;
            } else
                L--;

            if (k == L)
                return s[i];
        }

        return '.';
    }
};