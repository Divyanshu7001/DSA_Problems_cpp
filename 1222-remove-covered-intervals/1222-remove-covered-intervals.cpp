// Intuition

// The key observation is that an interval can only be covered by another interval that starts before (or at the same point) and ends after (or at the same point).
// To make this easy to detect, we first sort the intervals:
// Increasing order of start point so that any potential covering interval appears before the intervals it may cover.
// If two intervals have the same start, we sort them by decreasing end point. This ensures that the longer interval comes first, allowing the shorter one to be recognized as covered.
// While traversing the sorted intervals, we keep track of the farthest end point (maxEnd) seen so far.
// If the current interval ends before or at maxEnd, it is already covered by a previous interval.
// Otherwise, it is not covered, so we count it and update maxEnd.
// This way, every interval is processed only once after sorting, giving an efficient solution
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });

        int count = 0, maxEnd = 0;

        for (auto& interval : intervals) {
            if (interval[1] > maxEnd) {
                count++;
                maxEnd = interval[1];
            }
        }

        return count;
    }
};