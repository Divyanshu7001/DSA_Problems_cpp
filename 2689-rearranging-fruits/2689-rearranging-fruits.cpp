// Make frequecy maps of every item from both baskets
// every element has to appear even times..so that it can be distributed even
// times along both baskets

// Have an global vector to store which elements need to be swapped
// Simple seen to not iterate through the elements already seen

// Only store elements in the global vector when the freq. of elements in both
// the basket is different For this elements.. first get the difference of
// frequencies Swaps need to be done = difference / 2 while number of swaps
// exist..keep pushing in the vector

// Sort the vector
// after which..the things need to be swapped..i.e the cost will be on the left
// hand side of the vector iterate..see the value w.r.t the global minima , do
// the swaps accordingly Swap Logic: it can be of two types: A. Normal swap with
// min. element as the cost B. Use global minima to do the swapping ( here
// swapping happens two times) if current value >= 2 * global minimum value...
// Use indirect swap..otherwise use normal swap

// class Solution {
// public:
//     vector<int> vec; // Which elements need to be swapped
//     map<int, int> seen;
//     int calc(map<int, int>& f1, map<int, int>& f2) {
//         for (auto& [k, v] : f1) {
//             // Avoid going through same element again
//             if (seen[k])
//                 continue;
//             seen[k] = 1;
//             if ((f1[k] + f2[k]) % 2 == 1)
//                 return -1;
//             if (f1[k] != f2[k]) {
//                 int difference = abs(f1[k] - f2[k]);
//                 int extra = difference / 2;
//                 while (extra--) {
//                     vec.push_back(k);
//                 }
//             }
//         }
//         return 1;
//     }

//     long long minCost(vector<int>& basket1, vector<int>& basket2) {
//         map<int, int> mp1, mp2;
//         int globalMinima = 1e9;
//         for (auto& x : basket1) {
//             mp1[x]++;
//             globalMinima = min(globalMinima, x);
//         }
//         for (auto& x : basket2) {
//             mp2[x]++;
//             globalMinima = min(globalMinima, x);
//         }

//         if (calc(mp1, mp2) == -1)
//             return -1;
//         if (calc(mp2, mp1) == -1)
//             return -1;

//         sort(begin(vec), end(vec));
//         long long cost = 0;
//         int swap = 0;
//         for (int i = 0; i < vec.size() / 2; i++) {
//             if (vec[i] <= 2 * globalMinima) {
//                 swap += 2;
//                 cost += vec[i];
//             }
//         }
//         cost += (long long)(vec.size() - swap) * globalMinima;
//         return cost;
//     }
// };

// Optimized solution
// Use unordered_map for efficiency and it doesnt matter about the position
// anyway For extras finding: use one map...when going from basket1..do
// plus...going through basket2..do minus...at last will have extras only > 0

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> mp;
        int globalMinima = 1e9;
        for (auto& x : basket1) {
            mp[x]++;
            globalMinima = min(globalMinima, x);
        }
        for (auto& x : basket2) {
            mp[x]--;
            globalMinima = min(globalMinima, x);
        }

        vector<int> vec; // Which elements need to be swapped
        for (auto& [k, v] : mp) {
            if (abs(v) % 2 == 1)
                return -1;
            int difference = abs(v);
            int extra = difference / 2;
            while (extra--) {
                vec.push_back(k);
            }
        }

        sort(begin(vec), end(vec));
        long long cost = 0;
        int swap = 0;
        for (int i = 0; i < vec.size() / 2; i++) {
            if (vec[i] <= 2 * globalMinima) {
                swap += 2;
                cost += vec[i];
            }
        }
        cost += (long long)(vec.size() - swap) * globalMinima;
        return cost;
    }
};