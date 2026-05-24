class Solution {
public:
    int n;
    vector<int> t;
    int solve(vector<int>& arr, int i, int d) {
        if (t[i] != -1)
            return t[i];
        int res = 1;

        // Left go
        for (int j = i - 1; j >= max(0, i - d); j--) {
            if (arr[j] >= arr[i])
                break;
            res = max(res, 1 + solve(arr, j, d));
        }

        // Right go
        for (int j = i + 1; j <= min(n - 1, i + d); j++) {
            if (arr[j] >= arr[i])
                break;
            res = max(res, 1 + solve(arr, j, d));
        }

        return t[i] = res;
    }

    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        t.resize(n + 1, -1);
        int res = 1;
        for (int i = 0; i < n; i++) {
            res = max(res, solve(arr, i, d));
        }
        return res;
    }
};