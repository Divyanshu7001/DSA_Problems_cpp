class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime,
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

        int n = freeArray.size();
        vector<int> maxRightFree(n, 0);
        vector<int> maxLeftFree(n, 0);

        for (int i = n - 2; i >= 0; i--) {
            maxRightFree[i] = max(maxRightFree[i + 1], freeArray[i + 1]);
        }

        for (int i = 1; i < n; i++) {
            maxLeftFree[i] = max(maxLeftFree[i - 1], freeArray[i - 1]);
        }

        int result = 0;
        // Iterating over the freeArray
        for (int i = 1; i < n; i++) {
            int currentEventTime =
                endTime[i - 1] - startTime[i - 1]; // Current event time = d

            // Case-1: Moving the event completely into a different free time if
            // possible
            if (currentEventTime <= max(maxLeftFree[i - 1], maxRightFree[i])) {
                result = max(result, freeArray[i - 1] + currentEventTime +
                                         freeArray[i]);
            }

            // Case-2: Moving left or right to accomodate some space possible
            result = max(result, freeArray[i - 1] + freeArray[i]);
        }

        return result;
    }
};