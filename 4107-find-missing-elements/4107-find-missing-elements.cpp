class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        int maxEle = *max_element(nums.begin(), nums.end());
        vector<int> freq(maxEle, 0);

        int minEle = INT_MAX;
        for (int& num : nums) {
            freq[num - 1] = 1;
            minEle = min(minEle, num);
        }

        vector<int> res = {};
        int i = minEle;
        while (i < maxEle) {
            if (freq[i - 1] != 1)
                res.push_back(i);

            i++;
        }

        return res;
    }
};