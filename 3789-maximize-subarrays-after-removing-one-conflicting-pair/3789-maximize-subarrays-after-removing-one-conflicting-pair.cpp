// For ANY POINT, find all the restricting starting points
// Find the maximum & second maximum restricting starting points

// Valid subarrays possible = The point - maxRestrictingPoint
// Extras available = maxStartingPoint - secondMaxStartingPoint; (After removing
// the conflicting pair having maxRestrictingStartingPoint) Valid += extras have
// an global list to maintain how many extra subarrays we can get by removing
// some conflicting point

// At the last valid += max of the extra subarray global list

// T.C = O(n)+O(n+p)+O(n) = o(n)

#define SORT(x) begin(x),end(x)
class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {

        long long valid = 0;
        vector<vector<int>> conflictingPoints(n + 1);
        // conflictingPoints[i]=points which coflict with i

        // O(n)
        for (auto& p : conflictingPairs) {
            //(a,b)
            int a = min(p[0], p[1]);
            int b = max(p[0], p[1]);

            conflictingPoints[b].push_back(
                a); // so..b is the bigger points...by this line we set the
                    // smaller points as the conflicting one for the bigger
                    // one..how it should be
        }

        int maxConflict = 0, secondMaxConflict = 0;

        vector<long long> extra(n + 1, 0);
        // extra[i]=how many extra subarrays we can get by removing the
        // perticular i conflict point

        // overall = O(n+p)
        // O(n)
        for (int end = 1; end <= n;
             end++) { // Check all the conflicting points of end(as a point) by
                      // going into the list of conflictingPoints for this
                      // perticular end point

            // O(p)
            //  Total subarrays ending at the point end
            for (int& u : conflictingPoints[end]) {
                // in the list of conflicting points of end
                if (u >= maxConflict) {
                    secondMaxConflict = maxConflict;
                    maxConflict = u;
                } else if (u > secondMaxConflict) {
                    secondMaxConflict = u;
                }
            }

            valid += end - maxConflict;
            extra[maxConflict] += maxConflict - secondMaxConflict;
        }

        // for max_element=O(n)
        return valid + *max_element(SORT(extra));
    }
};