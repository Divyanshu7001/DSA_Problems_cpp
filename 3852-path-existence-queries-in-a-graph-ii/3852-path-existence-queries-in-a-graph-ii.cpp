class Solution {
public:
    int customUpperBound(vector<pair<int,int>>& arr, int target) {
        int n = arr.size(), l = 0, r = n - 1, res = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (arr[mid].first <= target) {
                res = mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }

        return res;
    }

    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                     vector<vector<int>>& queries) {

        // arr
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++)
            arr[i] = {nums[i], i};

        sort(begin(arr), end(arr));
        vector<int> nodeToIdx(n);
        for (int i = 0; i < n; i++) {
            int node = arr[i].second;
            nodeToIdx[node] = i;
        }

        int rows = n, cols = log2(n) + 1;
        vector<vector<int>> ancestorTable(rows, vector<int>(cols, 0));

        // Filling 0th column first
        for (int node = 0; node < n; node++) {
            int farthestIdxJump =
                customUpperBound(arr, arr[node].first + maxDiff);
            ancestorTable[node][0] = farthestIdxJump;
        }

        // Filling remaining cols
        for (int j = 1; j < cols; j++) {
            for (int node = 0; node < n; node++) {
                ancestorTable[node][j] =
                    ancestorTable[ancestorTable[node][j - 1]][j - 1];
            }
        }

        vector<int> res;
        for (auto& query : queries) {
            int u = query[0], v = query[1];
            int a = nodeToIdx[u], b = nodeToIdx[v];

            if (a == b) {
                res.push_back(0);
                continue;
            }

            if (a > b)
                swap(a, b);

            int curr = a;
            int jumps = 0;

            for (int j = cols - 1; j >= 0; j--) {
                if (ancestorTable[curr][j] < b) {
                    curr = ancestorTable[curr][j];
                    jumps += pow(2, j);
                }
            }

            if (ancestorTable[curr][0] >= b)
                res.push_back(jumps + 1);
            else
                res.push_back(-1);
        }

        return res;
    }
};