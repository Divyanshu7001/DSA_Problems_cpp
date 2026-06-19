class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int res = 0, prev = 0;
        for (int& g : gain) {
            prev += g;
            res = max(res, prev);
        }

        return res < 0 ? 0 : res;
    }
};