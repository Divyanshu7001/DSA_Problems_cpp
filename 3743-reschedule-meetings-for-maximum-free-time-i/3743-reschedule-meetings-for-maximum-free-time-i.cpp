class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                    vector<int>& endTime) {

        vector<int> freeArray; // Store the free durations

        // Free duration= ith event start time-(i-1)th end time
        // Suppose a event is starting at 1 time...but startTime is from 0
        // Then to get the 0 to 1 duration
        freeArray.push_back(startTime[0]);
        for (int i = 1; i < startTime.size(); i++) {
            freeArray.push_back(startTime[i] - endTime[i - 1]);
        }

        // Suppose last event is ending at 5 time...but endTime is 6
        // Then to get the 5 to 6 duration
        freeArray.push_back(eventTime - endTime[endTime.size() - 1]);

        // Sliding window
        int i = 0, j = 0, maxSum = 0, currSum = 0;
        int n = freeArray.size();
        while (j < n) {
            currSum += freeArray[j];

            if (i < n && j - i + 1 > k + 1) {
                currSum -= freeArray[i];
                i++;
            }

            maxSum = max(maxSum, currSum);
            j++;
        }

        return maxSum;
    }
};