class Solution {
public:
    int n;
    bool canReach(string s, int minJump, int maxJump) {

        n = s.length();
        vector<int> t(n, 0);
        // t[i]>0=>possible to reach here..else not

        t[0] = 1;
        int count = 0;
        for (int j = 1; j <= n - 1; j++) {
            if (j - minJump >= 0)
                count += t[j - minJump];

            if (j - maxJump - 1 >= 0)
                count -= t[j - maxJump - 1];

            if (count > 0 && s[j] == '0')
                t[j] = 1;
        }

        return t[n - 1] > 0;
    }
};

// memoization-> 117 case passed
//  class Solution {
//  public:
//      int n;

//     int solve(int i, string& s, int minJump, int maxJump, vector<int>& t) {
//         if (i == n - 1)
//             return true;

//         if (t[i] != -1)
//             return t[i];

//         for (int jump = minJump; jump <= maxJump; jump++) {
//             int j = i + jump;
//             if (j >= n)
//                 break;
//             if (s[j] == '0') {
//                 if (solve(j, s, minJump, maxJump, t) == true)
//                     return t[i] = true;
//             }
//         }

//         return t[i] = false;
//     }

//     bool canReach(string s, int minJump, int maxJump) {

//         n = s.length();
//         vector<int> t(n, -1);
//         return solve(0, s, minJump, maxJump, t);
//     }
// };