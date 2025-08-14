//Two pointers maintainig method
// class Solution {
// public:
//     string largestGoodInteger(string num) {
//         string maxElement = "";
//         int n = num.length();
//         int i = 0, j = 0, count = 0;
//         while (i < n && j < n) {
//             string temp = "";
//             if (num[i] == num[j]) {
//                 count++;
//                 if (count == 3) {
//                     if (num.substr(i, 3) > temp) {
//                         temp = num.substr(i, 3);
//                         maxElement = max(maxElement, temp);
//                     }
//                     i = j;
//                     j++;
//                     temp.clear();
//                     count = 0;
//                 } else {
//                     j++;
//                 }
//             } else {
//                 i++;
//                 count = 0;
//             }
//         }
//         return maxElement;
//     }
// };

//one pointer index maintain ..according just to this problem with 3 indexes
class Solution {
public:
    string largestGoodInteger(string num) {
        string maxElement = "";
        int n = num.length();

        for (int i = 0; i <= n - 3; i++) {
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
                string temp = num.substr(i, 3); // exactly 3 characters
                maxElement = max(maxElement, temp); // lexicographic works for equal-length strings
            }
        }

        return maxElement;
    }
};