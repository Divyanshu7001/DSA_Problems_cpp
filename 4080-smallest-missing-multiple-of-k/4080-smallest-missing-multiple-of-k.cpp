class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        vector<bool> isPresent(201, false);
        for (int& num : nums)
            isPresent[num - 1] = true;
        int i = 1;
        while (true) {
            k *= i;
            if (isPresent[k - 1] == false)
                break;
            k /= i;
            i++;
        }

        return k;
    }
};