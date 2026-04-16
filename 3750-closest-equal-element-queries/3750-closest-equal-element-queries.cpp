class Solution {
public:
    int bin_search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }

    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int m = queries.size(), n = nums.size();
        unordered_map<int, vector<int>> mp;
        // O(N)
        for (int i = 0; i < n; i++)
            mp[nums[i]].push_back(i);

        vector<int> res(m, -1);
        for (int i = 0; i < m; i++) {
            int idx = queries[i];
            int val = nums[idx];
            if (mp[val].size() == 1)
                continue;

            vector<int>& indexList = mp[val];
            int indexListsz = indexList.size();
            if (indexListsz == 2) {
                int dist = abs(indexList[1] - indexList[0]);
                int circularDist = n - dist;
                res[i] = min(dist, circularDist);
                continue;
            }

            int foundIndex = bin_search(indexList, idx);
            if (foundIndex == 0) {
                int forwardDist = abs(indexList[1] - indexList[0]);
                int circularDist =
                    n - abs(indexList[indexListsz - 1] - indexList[0]);
                res[i] = min(forwardDist, circularDist);
                continue;
            }

            if (foundIndex == indexListsz - 1) {
                // cout << "where i thought";
                int dist = abs(indexList[indexListsz - 1] -
                               indexList[indexListsz - 2]);
                int circularDist =
                    n - abs(indexList[indexListsz - 1] - indexList[0]);

                res[i] = min(dist, circularDist);
                continue;
            }

            res[i] =
                min(abs(indexList[foundIndex + 1] - indexList[foundIndex]),
                    abs(indexList[foundIndex] - indexList[foundIndex - 1]));
        }
        return res;
    }
};