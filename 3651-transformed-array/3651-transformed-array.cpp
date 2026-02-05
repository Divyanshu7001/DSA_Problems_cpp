class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);

        for (int i = 0; i < n; i++) {
            int num = nums[i], change = 0;
            if (num > 0) {
                change = abs(num % n);
            } else if (num < 0) {
                change = -abs(num % n);
            }
            int idx = abs((i + change + n)) % n;
            cout << i << " " << idx << endl;
            res[i] = nums[idx];
        }

        return res;
    }
};