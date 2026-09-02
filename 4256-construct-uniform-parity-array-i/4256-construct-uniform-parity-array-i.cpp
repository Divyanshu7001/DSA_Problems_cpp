//Parity rule=> even-odd=odd & odd-even=odd && even-even=even && odd-odd=even;
//so if all even or all odd=> true
//if mixed odd and even-> then take one odd ..if present value is odd..ignore or if even..then subtract , going to odd anyway..so everything can be done odd.
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        return true;
    }
};


//Brute force
// class Solution {
// public:
//     int n;
//     void solve(vector<int>& nums1, char ch, vector<bool>& res) {
//         for (int i = 0; i < n; i++) {
//             int val = nums1[i];
//             for (int j = 0; j < n; j++) {
//                 if (nums1[j] == val)
//                     continue;
//                 int diff = val - nums1[j];
//                 if (diff < 0)
//                     diff *= -1;

//                 if ((ch == 'O' && diff % 2 == 1) ||
//                     (ch == 'E' && diff % 2 == 0))
//                     res[diff - 1] = true;
//             }
//         }
//     }

//     bool uniformArray(vector<int>& nums1) {
//         n = nums1.size();
//         if (n == 1)
//             return true;
//         vector<bool> allOdd(101, false);
//         vector<bool> allEven(101, false);

//         for (int& num : nums1) {
//             if (num % 2 == 1)
//                 allOdd[num - 1] = true;
//             allEven[num - 1] = true;
//         }
//         int countE = count(allOdd.begin(), allOdd.end(), true);
//         int countO = count(allEven.begin(), allEven.end(), true);
//         if (countE == n || countO == n)
//             return true;

//         solve(nums1, 'O', allOdd);
//         solve(nums1, 'E', allEven);

//         int oddC = 0, evenC = 0;
//         for (int i = 0; i < 10; i++) {
//             if (allOdd[i] == true)
//                 oddC++;

//             if (allEven[i] == true)
//                 evenC++;
//         }

//         return (oddC == n || evenC == n) ? true : false;
//     }
// };
