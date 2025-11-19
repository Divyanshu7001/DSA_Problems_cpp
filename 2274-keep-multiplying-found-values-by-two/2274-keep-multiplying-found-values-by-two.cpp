// T.C=O(N)
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {

        unordered_set<int> st(nums.begin(), nums.end());
        while (true) {
            if (st.find(original) != st.end())
                original *= 2;
            else
                break;
        }
        return original;
    }
};