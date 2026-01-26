class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {

        vector<vector<int>> res;
        sort(arr.begin(), arr.end());

        int minDiff = INT_MAX, n = arr.size();

        for (int i = 1; i < n; i++) {
            minDiff = min(minDiff, (arr[i] - arr[i - 1]));
        }

        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] == minDiff) {
                res.push_back({arr[i - 1], arr[i]});
            }
        }
        return res;
    }
};