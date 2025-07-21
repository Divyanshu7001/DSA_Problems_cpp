// In-string update
//  class Solution {
//  public:
//      string makeFancyString(string s) {
//          int n = s.length();
//          int freqCount = 1;

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

// New result string making
class Solution {
public:
    string makeFancyString(string s) {
        int freqCount = 1;
        int i = 1;
        string result = "";
        result += s[0];
        while (i < s.size()) {
            if (s[i] == s[i - 1]) {
                ++freqCount;
                if (freqCount > 2) {
                    i++;
                } else
                    result += s[i];
            } else {
                result += s[i];
                freqCount = 1;
                i++;
            }
        }
        return result;
    }
};
