class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;

        // Count how many subarrays of size k each element appears in
        for (int i = 0; i <= n - k; i++) {
            unordered_set<int> uniqueElements(nums.begin() + i, nums.begin() + i + k);
            for (int num : uniqueElements) {
                freq[num]++;
            }
        }

        int res = -1;
        for (auto& pair : freq) {
            if (pair.second == 1) {
                res = max(res, pair.first);
            }
        }

        return res;
    }
};