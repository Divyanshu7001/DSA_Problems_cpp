//T.C=O(N)
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int result = 0;
        int prevTime = neededTime[0]; // time of last balloon in current same-color group

        for (int i = 1; i < colors.size(); i++) {
            if (colors[i] == colors[i - 1]) {
                result += min(prevTime, neededTime[i]);
                // Keep the max time balloon for next comparison
                prevTime = max(prevTime, neededTime[i]);
            } else {
                // New color group starts
                prevTime = neededTime[i];
            }
        }
        return result;
    }
};
