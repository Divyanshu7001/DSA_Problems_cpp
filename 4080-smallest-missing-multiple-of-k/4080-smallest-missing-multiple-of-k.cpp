class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        unordered_set<int> st(nums.begin(), nums.end());
        int i = 1;
        while (true) {
            k *= i;
            if (!st.count(k))
                break;
            k/=i;
            i++;
        }

        return k;
    }
};