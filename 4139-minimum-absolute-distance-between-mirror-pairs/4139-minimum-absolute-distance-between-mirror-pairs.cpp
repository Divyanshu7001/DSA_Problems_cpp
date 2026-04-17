class Solution {
public:
    int reverse(int num) {
        int res = 0;
        if (num < 10)
            return num;
        while (num > 0) {
            int dig = num % 10;
            res = (res * 10) + dig;
            num /= 10;
        }
        return res;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++)
            mp[nums[i]].push_back(i);

        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            int rev = reverse(nums[i]);
            if (!mp.count(rev))
                continue;

            vector<int>& indexList = mp[rev];
            auto it = upper_bound(indexList.begin(), indexList.end(), i);
            if (it != indexList.end())
                res = min(res, *it - i);
        }

        return res == INT_MAX ? -1 : res;
    }
};