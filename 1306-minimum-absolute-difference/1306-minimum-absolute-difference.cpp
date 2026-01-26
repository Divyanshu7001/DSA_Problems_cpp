class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {

        vector<vector<int>> res;
        sort(arr.begin(), arr.end());

        int minDiff = INT_MAX, n = arr.size();

        for (int i = 1; i < n; i++) {
            int diff = abs(arr[i] - arr[i - 1]);
            if (minDiff > diff)
                minDiff = diff;
        }

        for (int i = 1; i < n; i++) {
            if (abs(arr[i] - arr[i - 1]) == minDiff) {
                res.push_back({arr[i - 1], arr[i]});
            }
        }
        return res;
    }
};