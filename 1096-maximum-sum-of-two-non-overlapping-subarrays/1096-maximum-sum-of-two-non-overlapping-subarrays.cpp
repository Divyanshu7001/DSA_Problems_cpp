class Solution {
public:
    vector<int> prefSum;
    int solve(int L, int M) {
        int LmaxSum = 0, result = 0;

        for (int mEnd = L + M - 1; mEnd < prefSum.size(); mEnd++) {
            int mStart = mEnd - M + 1;
            int lEnd = mStart - 1;
            int lStart = lEnd - L + 1;

            int LcurrentSum =
                prefSum[lEnd] - ((lStart - 1 >= 0) ? prefSum[lStart - 1] : 0);

            int RcurrentSum = prefSum[mEnd] - prefSum[mStart - 1];

            LmaxSum = max(LmaxSum, LcurrentSum);

            result = max(result, LmaxSum + RcurrentSum);
        }
        return result;
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();

        prefSum.resize(n, 0);
        prefSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefSum[i] = nums[i] + prefSum[i - 1];
        }

        return max(solve(firstLen, secondLen), solve(secondLen, firstLen));
    }
};