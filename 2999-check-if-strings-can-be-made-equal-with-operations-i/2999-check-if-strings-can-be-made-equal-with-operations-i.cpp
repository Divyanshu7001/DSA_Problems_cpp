class Solution {
public:
    bool canBeEqual(string s1, string s2) {

        bool c1 = ((s1[0] == s2[0] && s1[2] == s2[2]) ||
                   (s1[0] == s2[2] && s1[2] == s2[0]));
        bool c2 = ((s1[1] == s2[1] && s1[3] == s2[3]) ||
                   (s1[1] == s2[3] && s1[3] == s2[1]));

        if (c1 && c2)
            return true;

        return false;
    }
};
// class Solution {
// public:
//     bool canBeEqual(string s1, string s2) {
//         unordered_set<char> st;
//         for (int i : {0, 2}) {
//             st.insert(s1[i]);
//             st.insert(s2[i]);
//         }

//         if (st.size() > 2)
//             return false;
//         st.clear();

//         for (int i : {1, 3}) {
//             st.insert(s1[i]);
//             st.insert(s2[i]);
//         }
//         if (st.size() > 2)
//             return false;

//         return true;
//     }
// };