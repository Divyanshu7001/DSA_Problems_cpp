class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {

        int maxCost = *max_element(costs.begin(), costs.end());
        vector<int> costList(maxCost + 1, 0);

        for (int& cost : costs)
            costList[cost]++;

        int total = 0;
        for (int cost = 0; cost <= maxCost; cost++) {
            if (costList[cost] == 0)
                continue;
            if (coins < cost)
                break;

            while (coins > 0 && costList[cost] > 0 && coins >= cost) {
                total++;
                coins -= cost;
                costList[cost]--;
            }
        }

        return total;
    }
};