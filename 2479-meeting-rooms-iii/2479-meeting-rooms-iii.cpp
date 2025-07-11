//Not done by me
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // Sort meetings by start time
        sort(meetings.begin(), meetings.end());

        // Min-heap for available rooms (by room number)
        priority_queue<int, vector<int>, greater<int>> available;
        for (int i = 0; i < n; ++i) available.push(i);

        // Min-heap for ongoing meetings: (end_time, room_number)
        using pii = pair<long long, int>;
        priority_queue<pii, vector<pii>, greater<pii>> ongoing;

        // Meeting counts per room
        vector<int> count(n, 0);

        for (auto& m : meetings) {
            long long start = m[0], end = m[1], duration = end - start;

            // Free up rooms
            while (!ongoing.empty() && ongoing.top().first <= start) {
                available.push(ongoing.top().second);
                ongoing.pop();
            }

            int room;
            long long actual_start;

            if (!available.empty()) {
                room = available.top(); available.pop();
                actual_start = start;
            } else {
                // Delay meeting to the earliest room that gets free
                auto [end_time, r] = ongoing.top(); ongoing.pop();
                room = r;
                actual_start = end_time;
            }

            count[room]++;
            ongoing.push({actual_start + duration, room});
        }

        // Find room with most meetings
        int maxCount = 0, result = 0;
        for (int i = 0; i < n; ++i) {
            if (count[i] > maxCount) {
                maxCount = count[i];
                result = i;
            }
        }

        return result;
    }
};