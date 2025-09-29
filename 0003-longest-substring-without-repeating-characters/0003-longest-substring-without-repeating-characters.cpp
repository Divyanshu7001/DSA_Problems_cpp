class Solution {
public:
    int result = 0;
    void solve(string s, int currentPos) {
        if (currentPos == s.size())
            return;
        unordered_set<char> st;
        int temp_count = 0;
        for (int i = currentPos; i < s.size(); i++) {
            if (st.count(s[i]))
                break;
            else {
                temp_count += 1;
                st.insert(s[i]);
                result = max(result, temp_count);
            }
        }
    }
    int lengthOfLongestSubstring(string s) {
        for (int i = 0; i < s.size(); i++) {
            solve(s, i);
        }
        return result;
    }
};