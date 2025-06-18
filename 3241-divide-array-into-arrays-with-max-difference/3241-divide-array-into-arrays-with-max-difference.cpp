class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        int numberOfArrays = n / 3;
        map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        vector<vector<int>> result;

        while (numberOfArrays > 0) {
            vector<int> temp;
            bool groupFormed = false;

            for (auto pair = mp.begin(); pair != mp.end();) {
                if (temp.empty() ||
                    (pair->first - temp.front() <= k && temp.size() < 3)) {
                    temp.push_back(pair->first);
                    pair->second--;
                    if (pair->second == 0) {
                        pair = mp.erase(pair);
                    } 
                    if (temp.size() == 3) {
                        cout << "Triggering inside temp size 3";
                        result.push_back(temp);
                        numberOfArrays--;
                        groupFormed = true;
                        break;
                    }
                } else {
                    ++pair;
                }
            }

            if (!groupFormed) {
                return {};
            }
        }

        return result;
    }
};
