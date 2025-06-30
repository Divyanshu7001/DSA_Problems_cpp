class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        int result = 0;

        for (int& num : nums) {
            mp[num]++;
        }

        for (int& num : nums) {
            int minNumber = num, maxNumber = num + 1;

            if (mp.count(maxNumber)) {
                result = max(result, mp[minNumber] + mp[maxNumber]);
            }
        }
        return result;
    }
};