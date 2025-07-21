//In-string update
// class Solution {
// public:
//     string makeFancyString(string s) {
//         int n = s.length();
//         int freqCount = 1;

//         for (int i = 1; i <= n; i++) {
//             if (s[i] == s[i - 1]) {
//                 if (freqCount >= 2) {
//                     s.erase(i, 1);
//                     n--;
//                     i--;
//                 } else
//                     freqCount++;
//             } else {
//                 freqCount = 1;
//             }
//         }
//         return s;
//     }
// };

//New result string making
// class Solution {
// public:
//     string makeFancyString(string s) {
//         int freqCount = 1;
//         int i = 1;
//         string result;
//         result.push_back(s[0]);
//         while (i < s.size()) {
//             if (s[i] == s[i - 1]) {
//                 ++freqCount;
//                 if (freqCount > 2) {
//                     i++;
//                 } else
//                     result.push_back(s[i]);
//             } else {
//                 result.push_back(s[i]);
//                 freqCount = 1;
//                 i++;
//             }
//         }
//         return result;
//     }
// };


//Optimal new string making
class Solution {
public:
    string makeFancyString(const string &s) {
        string result;
        result.reserve(s.size());

        for (char c : s) {
            int len = result.size();
            if (len >= 2 && result[len - 1] == c && result[len - 2] == c) {
                continue;
            }
            result.push_back(c);
        }
        return result;
    }
};
