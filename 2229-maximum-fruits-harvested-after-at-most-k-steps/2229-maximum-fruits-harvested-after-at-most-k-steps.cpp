// class Solution {
// public:
//     int maxFruits = 0;

//     void traversal(vector<vector<int>> slicedFruits, int k) {
//         int currentFruits = 0;
//         for (auto& f : slicedFruits) {
//             currentFruits += f[1];
//         }
//         maxFruits = max(maxFruits, currentFruits);
//     }

//     int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
//         // Slice range: only consider fruits within [startPos - k, startPos +
//         k] vector<vector<int>> validFruits;

//         if (startPos == 0) {
//             for (auto& f : fruits) {
//                 if (f[0] >= startPos && f[0] <= startPos + k) {
//                     validFruits.push_back(f);
//                 }
//             }
//             traversal(validFruits, k);
//         } else if (startPos == fruits.size()) {
//             for (auto& f : fruits) {
//                 if (f[0] >= startPos - k && f[0] <= startPos) {
//                     validFruits.push_back(f);
//                 }
//             }
//             traversal(validFruits, k);
//         } else {
//             for (auto& f : fruits) {
//                 if (f[0] >= startPos - k && f[0] <= startPos + k) {
//                     validFruits.push_back(f);
//                 }
//             }
//             // Split validFruits into left and right sides based on startPos
//             vector<vector<int>> leftFruits, rightFruits;

//             for (auto& f : validFruits) {
//                 if (f[0] < startPos)
//                     leftFruits.push_back(f);
//                 else
//                     rightFruits.push_back(f);
//             }

//             traversal(leftFruits, k);
//             traversal(rightFruits, k);
//         }

//         return maxFruits;
//     }
// };

// Logic:

// Case-1
// Have to traverse to left as much as possible ..then comeback to right
// Supposing control traverses 'd' distance in left
// Then total valid range of fruits to be extracted =>
// left = (position - d) => find lowerbound(left)
// right = (position + K - 2*d) => find upperbound(right)-1

// The value of supposed 'd'=>
//  k-2*d >= 0 => k <= d/2
//..therefore it cant be more than half of d

// Case-2
// Supposing that control traverses right 'd' distance..comes back & then goes
// to left right = (p+d) left = p-(k-2*d)

// Keep accumulating prefix sum to get the total fruits value of this perticular
// range in constant time prefix[right]-prefix[left-1]


//T.C=O(k*logn)
//S.C=O(n)
class Solution {
public:
    int maxFruits = 0;

    void traversal(vector<vector<int>> slicedFruits, int k) {
        int currentFruits = 0;
        for (auto& f : slicedFruits) {
            currentFruits += f[1];
        }
        maxFruits = max(maxFruits, currentFruits);
    }

    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();

        vector<int> prefixSum(n);
        vector<int> positions(
            n); // Positions stored will be always in sorted fashion

        for (int i = 0; i < n; i++) {
            positions[i] = fruits[i][0];

            prefixSum[i] = fruits[i][1] + (i > 0 ? prefixSum[i - 1] : 0);
        }

        int maxFruits = 0;
        
        //O(k)
        for (int d = 0; d <= k / 2; d++) {
            // Case-1: moved 'd' steps to the left
            int remaining = k - 2 * d;
            int i = startPos - d;
            int j = startPos + remaining;

            //O(logn) complexity as the lower_bound and upper_bound are binary search techniques
            int left = lower_bound(begin(positions), end(positions), i) -
                       begin(positions);
            int right = upper_bound(begin(positions), end(positions), j) -
                        begin(positions) - 1;

            if (left <= right) {
                int total =
                    prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
                maxFruits = max(maxFruits, total);
            }

            // Case-2: moved 'd' steps to the right hand
            // remain: k=2*d

            i = startPos - remaining;
            j = startPos + d;

            left = lower_bound(begin(positions), end(positions), i) -
                   begin(positions);
            right = upper_bound(begin(positions), end(positions), j) -
                    begin(positions) - 1;

            if (left <= right) {
                int total = prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
                maxFruits = max(maxFruits, total);
            }
        }
        return maxFruits;
    }
};
