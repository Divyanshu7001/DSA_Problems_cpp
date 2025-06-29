// Bruete Forc/ Simulation is too big
// Binary search approach with number of sequences pre-determined in a vector

// Approach:
// 1.Sort the arrray
// hold the power according to the index element i.e in 2^i power
// 1->2^1=2
// 2->2^2=4
// 3->2^3=8 etc..

// have a integer value rersult to hold number of subsequences
// keep doing binary search
// as vector is sorted i.e min element at first and maximum at last
// if vector[left]=vector[right]<=target ...left forward & add sequences number
// into result else right backward
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> power(n, 1);
        for (int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * 2) % mod;
        }

        int left = 0, right = n - 1, result = 0;
        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                result = (result + power[right - left]) % mod;
                left++;
            } else
                right--;
        }
        return result;
    }
};