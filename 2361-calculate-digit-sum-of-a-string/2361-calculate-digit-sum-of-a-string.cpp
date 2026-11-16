class Solution {
public:
    string solve(string s, int a, int b) {
        int sum = 0;
        if (a == b)
            return to_string(s[a]);
        for (int i = a; i < b; i++)
            sum+=s[i]-'0';
        
        return to_string(sum);
    }
    string digitSum(string s, int k) {
        if (s.length() <= k)
            return s;

        while (s.length() > k) {
            int i = 0;
            string temp = "";
            while (i < s.length()) {
                temp += solve(s, i, i + k < s.length() ? i + k : s.length());
                i += k;
            }
            s = temp;
        }

        return s;
    }
};