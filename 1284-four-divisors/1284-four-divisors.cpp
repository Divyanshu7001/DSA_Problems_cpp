class Solution {
public:
    unordered_map<int, int> mp;
    int solve(int num) {
        if (mp.count(num))
            return mp[num];
        int ans = 1 + num, divCount = 2;
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                ans += i;
                int other = num / i;
                if (other == i) {
                    divCount += 1;
                } else {
                    divCount += 2;
                    ans += other;
                }
                if (divCount > 4)
                    break;
            }
        }
        if (divCount == 4) {
            mp[num] = ans;
        } else
            mp[num] = 0;
        return divCount == 4 ? ans : 0;
    }

    int sumFourDivisors(vector<int>& nums) {

        int ans = 0;

        for (int num : nums)
            ans += solve(num);

        return ans;
    }
};