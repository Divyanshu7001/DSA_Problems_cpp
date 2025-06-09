class Solution {
public:
    long long countSteps(int n, long long curr, long long next) {
        long long steps = 0;
        while (curr <= n) {
            long long upper = min((long long)n + 1, next);
            steps += upper - curr;
            curr *= 10;
            next *= 10;
        }
        return steps;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;

        while (k > 0) {
            long long steps = countSteps(n, curr, curr + 1);
            if (steps <= k) {
                curr++;
                k -= steps;
            } else {
                curr *= 10;
                k--;
            }
        }
        return curr;
    }
};
