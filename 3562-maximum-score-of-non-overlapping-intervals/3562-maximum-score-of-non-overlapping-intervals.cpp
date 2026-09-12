class Solution {
public:
    struct Node {
        long long score = -1;
        vector<int> idxs;
    };

    int n;
    vector<int> nextIdx;
    // memo
    vector<vector<Node>> t;

    int findNext(vector<vector<int>>& intervals, int r) {
        int l = 0, h = n - 1;
        int result = n;

        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (intervals[mid][0] > r) {
                result = mid;
                h = mid - 1;
            } else
                l = mid + 1;
        }
        return result;
    }

    Node solve(vector<vector<int>>& intervals, int i, int k) {
        if (k == 0 || i >= n)
            return Node();

        if (t[i][k].score != -1)
            return t[i][k];

        // skip case
        Node skip = solve(intervals, i + 1, k);

        // current interval data
        int weight = intervals[i][2];
        int idx = intervals[i][3];
        int nextIndex = nextIdx[i];

        // take case
        Node temp = solve(intervals, nextIdx[i], k - 1);
        Node take;
        take.score = temp.score + weight;
        take.idxs = temp.idxs;
        take.idxs.push_back(idx);

        sort(begin(take.idxs), end(take.idxs));

        Node result;
        if (skip.score > take.score)
            result = skip;
        else if (skip.score < take.score)
            result = take;
        else
            result = (skip.idxs < take.idxs) ? skip : take;

        return t[i][k] = result;
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();

        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }

        sort(begin(intervals), end(intervals));
        nextIdx.resize(n);

        for (int i = 0; i < n; i++) {
            int end = intervals[i][1];
            nextIdx[i] = findNext(intervals, end); // binary search
        }

        // max 4 indices to be taken
        t.resize(n + 1, vector<Node>(4 + 1));
        return solve(intervals, 0, 4).idxs;
    }
};