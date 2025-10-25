// T.C=O(N)
class Solution {
public:
    int totalMoney(int n) {
        if (n == 1)
            return 1;
        int previousMoney = 1, currentDay = 2, weeklyStart = 1, money = 1;
        while (currentDay <= n) {
            if (currentDay % 7 == 1) {
                weeklyStart++;
                previousMoney = weeklyStart;
            } else {
                previousMoney++;
            }
            money += previousMoney;
            currentDay++;
        }
        return money;
    }
};