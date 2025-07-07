class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();

        sort(begin(events), end(events));

        priority_queue<int, vector<int>, greater<int>> pq; // min-heap

        int day = 1;
        int i = 0, count = 0;

        // Find the maximum day to know when to stop
        int max_day = 0;
        for (const auto& e : events) {
            max_day = max(max_day, e[1]);
        }

        for (day = 1; day <= max_day; ++day) {
            // Add all events starting today
            while (i < n && events[i][0] == day) {
                pq.push(events[i][1]);
                i++;
            }

            // Remove expired events
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }

            // Attend one event (with earliest end day)
            if (!pq.empty()) {
                pq.pop();
                count++;
            }
        }

        return count;
    }
};
