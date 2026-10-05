//TC=O(n)
//SC=O(n)
class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0, n = s.length();
        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(score);
                score=0;
            } else {
                if (s[i - 1] == '(') // simple case
                    score = st.top() + 1;
                else { // nested case
                    score = st.top() + (2 * score);
                }
                st.pop();
            }
        }
        return score;
    }
};