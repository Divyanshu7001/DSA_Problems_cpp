class Solution {
public:
    int minElement(vector<int>& nums) {
        int minimum = INT_MAX;
        for (int& num : nums) {
            int res = 0;
            if (num <= 9)
                res = num;
            else {
                while (num > 0) {
                    res += num % 10;
                    num /= 10;
                }
            }
            minimum = min(minimum, res);
        }
        return minimum;
    }
};

// class Solution {
// public:
//     int minElement(vector<int>& nums) {
//         int minimum = INT_MAX;
//         for (int& num : nums) {
//             string word = to_string(num);
//             int res = 0;
//             for (char& ch : word) {
//                 res += ch - '0';
//             }
//             minimum = min(minimum, res);
//         }
//         return minimum;
//     }
// };