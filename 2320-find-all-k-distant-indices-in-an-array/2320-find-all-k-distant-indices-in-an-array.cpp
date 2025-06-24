class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> result;
        int n = nums.size();
        vector<int> store;
        for (int i = 0; i < n; i++) {
            if (nums[i] == key)
                store.push_back(i);
        }

        for (int i = 0; i < n; i++) {
            for (int idx : store) {
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