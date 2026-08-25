class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        unordered_set<int> st(nums.begin(), nums.end());
        int i = 1, res;
        while (true) {
            res = k * i;
            i++;
            if (!st.count(res))
                break;
        }

        return res;
    }
};