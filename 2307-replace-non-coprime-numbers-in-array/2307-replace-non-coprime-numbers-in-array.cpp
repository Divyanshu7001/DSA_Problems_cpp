class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {

        vector<int> result;

        for (int x : nums) {
            result.push_back(x);

            while (result.size() > 1) {
                int a = result[result.size() - 2],
                    b = result[result.size() - 1];
                if (gcd(a, b) == 1)
                    break;

                long long lcmValue = lcm((long long)a, (long long)b);
                result.pop_back();
                result.back() = (int)lcmValue;
            }
        }
        return result;
    }
};