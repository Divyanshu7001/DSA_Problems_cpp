// From pattern of answers according to the n size...
// for n, the answer is nearest 2^x i.e for n=3..it will be 4, for
// n=4,5,6,7...it will be 8 etc for n==1,2..it will be n itself

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        int n = nums.size();

        if (n == 1 || n == 2)
            return n;

        int ans = 1;
        while (ans <= n)
            ans *= 2;

        return ans;
    }
};