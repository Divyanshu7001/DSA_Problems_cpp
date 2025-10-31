// T.C=O(N)
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {

        vector<int> result;
        vector<int> mp(101, 0);

        for (int num : nums) {
            mp[num]++;
        }

        for (int i = 0; i < 101; i++) {
            if (mp[i] > 1)
                result.push_back(i);
        }

        return result;
    }
};