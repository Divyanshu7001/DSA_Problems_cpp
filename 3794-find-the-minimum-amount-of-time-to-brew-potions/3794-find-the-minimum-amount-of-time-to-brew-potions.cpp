class Solution {
public:
    long long minTime(vector<int>& skills, vector<int>& mana) {

        int n = skills.size(), m = mana.size();

        vector<long long> finishTime(
            n, 0); // finishTime[i] = when wizard i finishes current potion

        for (int j = 0; j < m; ++j) {

            finishTime[0] += 1LL * mana[j] * skills[0];

            for (int i = 1; i < n; ++i)

                finishTime[i] = max(finishTime[i], finishTime[i - 1]) +
                                1LL * mana[j] * skills[i];

            for (int i = n - 1; i > 0; --i)

                finishTime[i - 1] = finishTime[i] - 1LL * mana[j] * skills[i];
        }

        return finishTime[n - 1];
    }
};