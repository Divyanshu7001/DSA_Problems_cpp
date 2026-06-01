class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.begin(), cost.end(), greater<int>());

        int res = 0, i = 1;
        while (i <= n) {
            if (i % 3 != 0) {
                res += cost[i - 1];
            } 
            i++;
        }

        return res;
    }
};