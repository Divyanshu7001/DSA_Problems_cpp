class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int result = numBottles;
        while (numBottles / numExchange != 0) {
            int exchangedBottles = numBottles / numExchange;
            result += exchangedBottles;
            numBottles = exchangedBottles + (numBottles % numExchange);
        }
        return result;
    }
};