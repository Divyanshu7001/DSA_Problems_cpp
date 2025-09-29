// class Solution {
// public:
//     int result = 0;
//     void solve(string s, int currentPos) {
//         if (currentPos == s.size())
//             return;
//         unordered_set<char> st;
//         int temp_count = 0;
//         for (int i = currentPos; i < s.size(); i++) {
//             if (st.count(s[i]))
//                 break;
//             else {
//                 temp_count += 1;
//                 st.insert(s[i]);
//                 result = max(result, temp_count);
//             }
//         }
//     }
//     int lengthOfLongestSubstring(string s) {
//         for (int i = 0; i < s.size(); i++) {
//             solve(s, i);
//         }
//         return result;
//     }
// };


//sliding window
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int left = 0, result = 0;

        for (int right = 0; right < s.size(); right++) {
            while (st.count(s[right])) {
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            result = max(result, right - left + 1);
        }

        return result;
    }
};
