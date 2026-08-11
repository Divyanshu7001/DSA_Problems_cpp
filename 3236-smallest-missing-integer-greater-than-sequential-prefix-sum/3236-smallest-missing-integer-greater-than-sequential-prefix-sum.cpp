class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());

        int seqSum = nums[0];
        for (int j = 1; j < n; j++) {
            if ((nums[j] - nums[j - 1]) == 1)
                seqSum += nums[j];
            else
                break;
        }
        while (st.count(seqSum))
            seqSum++;

        return seqSum;
    }
};