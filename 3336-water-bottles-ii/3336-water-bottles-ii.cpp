class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int result = numBottles;
        while (numBottles / numExchange != 0) {
            result++;
            numBottles = numBottles - numExchange + 1;
            numExchange++;
        }
        return result;
    }
};