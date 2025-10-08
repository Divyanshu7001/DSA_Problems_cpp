class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();
        vector<int> ans;

        for (long long spell : spells) {
            // Minimum potion strength required for success
            long long minPotion =
                (success + spell - 1) / spell; // ceil(success / spell)

            // Find the first potion >= minPotion
            auto it = lower_bound(potions.begin(), potions.end(), minPotion);

            // Count of successful potions
            ans.push_back(potions.end() - it);
        }

        return ans;
    }
};