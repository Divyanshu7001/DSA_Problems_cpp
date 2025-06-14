// Standard Library approach
// T.c=(log(num))
// S.C=(log(num))
// class Solution {
// public:
//     int minMaxDifference(int num) {

//         string str1 = to_string(num);
//         string str2 = str1;

//         int idx = str1.find_first_not_of('9');
//         if (idx != string::npos) {
//             char ch = str1[idx];
//             replace(begin(str1), end(str1), ch, '9');
//         }

//         char ch = str2[0];
//         replace(begin(str2), end(str2), ch, '0');

//         return stoi(str1) - stoi(str2);
//     }
// };

// Iterative approach
// T.C=S.C=O(Log(Num))
class Solution {
public:
    int minMaxDifference(int num) {
        string str1 = to_string(num);
        string str2 = str1;

        int n = str1.length();

        // Maximizing String1 by changing most significant bit which is not 9 to
        // 9
        for (int i = 0; i < n; i++) {
            if (str1[i] != '9') {
                char valueToMaximize = str1[i];
                for (int j = i; j < n; j++) {
                    if (str1[j] == valueToMaximize) {
                        str1[j] = '9';
                    }
                }
                break;
            }
        }

        // Minimizing String 2 by taking the most significant value and making
        // it 0
        char valueToMinimize = str2[0];
        for (int j = 0; j < n; j++) {
            if (str2[j] == valueToMinimize) {
                str2[j] = '0';
            }
        }
        return stoi(str1) - stoi(str2);
    }
};