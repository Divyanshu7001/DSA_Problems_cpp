class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long res = (long long)happiness[0];

        for (int i = 1; i < k; i++) {
            int current = happiness[i] - i;
            if (current <= 0)
                break;
            res += current;
        }

        return res;
    }
};