// T.C=O(N)
class Solution {
public:
    int weeklyStart = 1, money = 1;
    void solve(int currentDay, int previousMoney, int targetDay) {
        if (currentDay % 7 == 1) {
            weeklyStart++;
            money += weeklyStart;
            if (currentDay == targetDay) {
                return;
            }
            solve(currentDay + 1, weeklyStart, targetDay);
        } else {
            previousMoney += 1;
            money += previousMoney;
            if (currentDay == targetDay) {
                return;
            }
            solve(currentDay + 1, previousMoney, targetDay);
        }
    }
    int totalMoney(int n) {
        if (n == 1)
            return 1;
        solve(2, 1, n);
        return money;
    }
};