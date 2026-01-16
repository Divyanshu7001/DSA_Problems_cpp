class Solution {
public:
    int M = 1e9 + 7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences,
                           vector<int>& vFences) {

        hFences.push_back(1);
        hFences.push_back(m);
        sort(hFences.begin(), hFences.end());

        vFences.push_back(1);
        vFences.push_back(n);
        sort(vFences.begin(), vFences.end());

        unordered_set<int> hset;

        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++)
                hset.insert(abs(hFences[i] - hFences[j]));
        }

        int best = 0;
        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                int gap = abs(vFences[i] - vFences[j]);
                if (hset.count(gap))
                    best = max(best, gap);
            }
        }

        return best == 0 ? -1 : (1LL * best * best) % M;
    }
};