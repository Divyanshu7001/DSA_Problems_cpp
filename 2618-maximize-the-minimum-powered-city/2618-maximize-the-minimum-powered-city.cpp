

// Approach (Binary search along with Difference Array Technique for
// optimisation

// T.C : O(n * log(sum+k)), sum = sum of station values

// S.C : O(n)

class Solution {

public:
    bool check(long long mid, vector<long long>& diff, int n, int r, int k) {

        vector<long long> tempDiff = diff;

        long long cumSum = 0;

        for (int i = 0; i < n; i++) {

            cumSum += tempDiff[i];

            if (cumSum < mid) {

                long long need = mid - cumSum;

                if (need > k)

                    return false;

                k -= need;

                cumSum += need;

                // Gredily adding the value to (i+r)th city because it will
                // anyways cover ith city.

                // And using difference array technique below to find cumulative
                // sum

                int idx = i + 2 * r + 1;

                if (idx < n)

                    tempDiff[idx] -= need;
            }
        }

        return true;
    }

    long long maxPower(vector<int>& stations, int r, int k) {

        int n = stations.size();

        vector<long long> diff(n + 1, 0);

        // Build difference array

        for (int i = 0; i < n; i++) {

            diff[max(0, i - r)] += stations[i];

            if (i + r + 1 < n)

                diff[i + r + 1] -= stations[i];
        }

        long long left = *min_element(stations.begin(), stations.end());

        long long right = accumulate(stations.begin(), stations.end(), 0LL) + k;

        // Binary search

        while (left < right) {

            long long mid = left + (right - left + 1) / 2;

            if (check(mid, diff, n, r, k))

                left = mid;

            else

                right = mid - 1;
        }

        return left;
    }
};