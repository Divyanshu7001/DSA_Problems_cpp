class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        int target = sum % p;
        if (target == 0) return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;  // prefix before start
        long long prefix = 0;
        int res = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            prefix = (prefix + nums[i]) % p;
            int need = (prefix - target + p) % p;

            if (mp.count(need))
                res = min(res, i - mp[need]);

            mp[prefix] = i;
        }

        return res == nums.size() ? -1 : res;
    }
};



// class Solution {
// public:
//     int solve(vector<int>& nums, int want) {
//         int n = nums.size();
//         for (int i = 0; i < n; i++) {
//             int temp = want;
//             temp -= nums[i];
//             for (int j = i + 1; j < n; j++) {
//                 temp -= nums[j];
//                 if (temp == 0)
//                     return j - i + 1;
//                 if (temp < 0)
//                     break;
//             }
//         }
//         return -1;
//     }

//     int minSubarray(vector<int>& nums, int p) {

//         long long sum = accumulate(nums.begin(), nums.end(), 0LL); // FIX

//         if (sum < p)
//             return -1;
//         if (sum % p == 0)
//             return 0;

//         int want = sum % p;
//         if (find(nums.begin(), nums.end(), want) != nums.end())
//             return 1;

//         int res = solve(nums, want);
//         return res;
//     }
// };