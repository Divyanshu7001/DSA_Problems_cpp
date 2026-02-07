class Solution {
public:
    int minimumDeletions(string s) {

        int n = s.length();

        if (n == 1)
            return 0;

        int res = 0;
        stack<char> st;

        for (int i = 0; i < n; i++) {
            if (!st.empty() && s[i] == 'a' && st.top() == 'b') { //'ba'
                st.pop();
                res++;
            } else
                st.push(s[i]);
        }

        return res;
    }
};