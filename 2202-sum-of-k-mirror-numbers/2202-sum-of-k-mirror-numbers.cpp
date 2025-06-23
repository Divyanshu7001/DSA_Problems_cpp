// Brute Force
// Simulation approach
// Not optimal in any way
// takes too much time
//  #define ll long long
//  class Solution {
//  public:
//      bool isPalindrome(int number) {
//          string s = to_string(number);
//          int i = 0, j = s.length() - 1;

//         while (i < j) {
//             if (s[i] != s[j]) {
//                 return false;
//             }
//             i++;
//             j--;
//         }
//         return true;
//     }
//     int findBaseNumber(int number, int& base) {
//         if (number == 0)
//             return 0;

//         int result = 0;
//         int place = 1;

//         while (number > 0) {
//             int remainder = number % base;
//             result += remainder * place;
//             number /= base;
//             place *= 10;
//         }
//         return result;
//     }

//     long long kMirror(int k, int n) {
//         ll sum = 0;
//         int count = 0;
//         int i = 1;
//         while (count != n) {
//             int kBaseNumber = findBaseNumber(i, k);
//             if (isPalindrome(i) && isPalindrome(kBaseNumber)) {
//                 count++;
//                 sum += i;
//             }
//             i++;
//         }
//         return sum;
//     }

// };

#define ll long long
class Solution {
public:
    bool isPalindrome(string number) {
        int i = 0, j = number.length() - 1;

        while (i <= j) {
            if (number[i] != number[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    string findBaseNumber(ll number, int base) {
        if (number == 0)
            return "0";

        string result = "";
        while (number > 0) {
            result += to_string(number % base);
            number /= base;
        }
        return result;
    }

    long long kMirror(int k, int n) {
        ll sum = 0;
        int l = 1;

        while (n > 0) {
            int half_length = (l + 1) / 2;
            ll min_num = pow(10, half_length - 1);
            ll max_num = pow(10, half_length) - 1;

            for (int num = min_num; num <= max_num; num++) {
                string first_half = to_string(num);
                string second_half = first_half;
                reverse(begin(second_half), end(second_half));

                string pal = "";
                if (l % 2 == 0) { // Even length palindrome
                    pal = first_half + second_half;
                } else {
                    pal = first_half + second_half.substr(1);
                }

                ll pal_num = stoll(pal);
                string baseK = findBaseNumber(pal_num, k);

                if (isPalindrome(baseK)) {
                    sum += pal_num;
                    n--;
                    if (n == 0)
                        break;
                }
            }
            l++;
        }
        return sum;
    }
};