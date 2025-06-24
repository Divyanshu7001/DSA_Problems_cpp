class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> result;
        int n = nums.size();
        pair<int, vector<int>> store;
        store.first = key;
        for (int i = 0; i < n; i++) {
            if (nums[i] == key)
                store.second.push_back(i);
        }

        for (int i = 0; i < n; i++) {
            for (int idx : store.second) {
                if (abs(i - idx) <= k) {
                    result.push_back(i);
                    break;
                }
            }
        }

        sort(result.begin(), result.end());

        return result;
    }
};