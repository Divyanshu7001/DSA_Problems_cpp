class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    long long gcdSum(vector<int>& nums) {

        vector<int> prefixGcd;
        int mx = nums[0];

        // n*log(min(a,b))
        for (int& num : nums) {
            mx = max(mx, num);
            prefixGcd.push_back(gcd(num, mx));
        }

        // nlogn
        sort(begin(prefixGcd), end(prefixGcd));

        int i = 0, j = prefixGcd.size() - 1;
        long long res = 0;
        
        while (i < j) {
            res += gcd(prefixGcd[i], prefixGcd[j]);
            i++;
            j--;
        }
        return res;
    }
};