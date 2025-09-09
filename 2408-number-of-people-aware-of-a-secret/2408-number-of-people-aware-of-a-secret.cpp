//T.C=O(n*(forget-delay))
class Solution {
public:
    int MOD = 1e9 + 7;
    vector<int> t;
    // Returns the number of persons who know the secret on the passed day
    int solve(int day, int delay, int forget) {
        if (day == 1)
            return 1;

        if (t[day] != -1) {
            return t[day];
        }
        int result = 0;
        for (int prev = day - forget + 1; prev <= day - delay; prev++) {
            if (prev > 0) {
                result = (result + solve(prev, delay, forget)) % MOD;
            }
        }

        return t[day] = result;
    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        int total = 0;
        t.assign(n + 1, -1);
        for (int day = n - forget + 1; day <= n; day++) {
            if (day > 0) {
                total = (total + solve(day, delay, forget)) % MOD;
            }
        }
        return total;
    }
};

// class Solution {
// public:
//     int MOD = 1e9 + 7, totalDays, total = 0;

//     void solve(int currentDay, int delay, int forget) {
//         int currentDelay = delay, currentForgetDay = forget;
//         while (currentDay <= totalDays && currentForgetDay >= 0) {
//             if (currentDelay > 0) {
//                 currentDelay--;
//             } else {
//                 solve(currentDay, delay, forget);
//                 total++;
//             }
//             currentForgetDay--;
//             currentDay++;
//         }
//         if (currentForgetDay == 0 && currentDay != totalDays) {
//             total--;
//         }
//     }

//     int peopleAwareOfSecret(int n, int delay, int forget) {
//         totalDays = n;
//         solve(1, delay, forget);
//         return total % MOD;
//     }
// };