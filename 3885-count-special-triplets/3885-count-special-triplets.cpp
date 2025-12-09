class Solution {
public:
    int MOD = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {

        unordered_map<int, int> mp;
        for (int num : nums)
            mp[num]++;

        unordered_map<int, int> prefix;
        long long ans = 0;
        for (int i : nums) {
            int totalFreq = mp[2 * i];
            int leftFreq = prefix[2 * i];
            int rightFreq = totalFreq - leftFreq;
            if (i == 0)
                rightFreq--;
            prefix[i]++;

            ans = (ans + leftFreq * 1LL * rightFreq) % MOD;
        }
        return ans;
    }
};