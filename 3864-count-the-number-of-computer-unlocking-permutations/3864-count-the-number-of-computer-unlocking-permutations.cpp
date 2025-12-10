class Solution {
public:
    int countPermutations(vector<int>& complexity) {

        int n = complexity.size();
        int M = 1e9 + 7;
        long long res = 1;
        for (int i = 1; i < n; i++) {
            if (complexity[i] <= complexity[0])
                return 0;

            res = (res * i) % M;
        }

        return res;
    }
};