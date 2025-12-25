class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {

        sort(happiness.begin(), happiness.end(), greater<int>());
        long long res = happiness[0];

        for (int i = 1; i < k; i++) {
            int current = happiness[i] - i;
            if (current <= 0)
                break;
            res += current;
        }

        return res;
    }
};