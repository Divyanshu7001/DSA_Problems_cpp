class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size(), filledFruits = 0;
        vector<int> filled(n,false);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (fruits[i] <= baskets[j] && !filled[j]) {
                    filled[j] = true;
                    filledFruits += 1;
                    break;
                }
            }
        }
        return n - filledFruits;
    }
};