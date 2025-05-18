// Brute force non-optimized approach
//  class Solution {
//  public:
//      vector<string> columnStates;
//      int M = 1e9 + 7;
//      void generateColumnStates(string curr, char prevChar, int l, int m) {
//          if (l == m) {
//              columnStates.push_back(curr);
//              return;
//          }

//         for (char ch : {'R', 'G', 'B'}) {
//             if (ch == prevChar) {
//                 continue;
//             }
//             generateColumnStates(curr + ch, ch, l + 1, m);
//         }
//     }

//     int solve(int remainingColumns, int prevIndex, int m) {
//         if (remainingColumns == 0) {
//             return 1;
//         }

//         int ways = 0;
//         string prevState = columnStates[prevIndex];

//         for (int i = 0; i < columnStates.size(); i++) {
//             if (i == prevIndex)
//                 continue;

//             string currState = columnStates[i];
//             bool valid = true;

//             // Loop to iterate over current state and prevState to avoid
//             // adjacent matching problem
//             for (int j = 0; j < m; j++) {
//                 if (prevState[j] == currState[j]) {
//                     valid = false;
//                     break;
//                 }
//             }

//             if (valid) {
//                 ways = (ways + solve(remainingColumns - 1, i, m)) % M;
//             }
//         }
//         return ways;
//     }

//     int colorTheGrid(int m, int n) {
//         // Step-1: Generate Column states
//         generateColumnStates("", '#', 0, m);

//         int result = 0;
//         for (int i = 0; i < columnStates.size(); i++) {
//             result = (result + solve(n - 1, i, m)) % M;
//         }

//         return result;
//     }
// };

// Optimized 2-d vector approach of int,int type to store and check the ways
// already available to avoid iterating redundant ones
class Solution {
public:
    vector<string> columnStates;
    int M = 1e9 + 7;
    vector<vector<int>> t;
    void generateColumnStates(string curr, char prevChar, int l, int m) {
        if (l == m) {
            columnStates.push_back(curr);
            return;
        }

        for (char ch : {'R', 'G', 'B'}) {
            if (ch == prevChar) {
                continue;
            }
            generateColumnStates(curr + ch, ch, l + 1, m);
        }
    }

    int solve(int remainingColumns, int prevIndex, int m) {
        if (remainingColumns == 0) {
            return 1;
        }

        if (t[remainingColumns][prevIndex] != -1) {
            return t[remainingColumns][prevIndex];
        }

        int ways = 0;
        string prevState = columnStates[prevIndex];

        for (int i = 0; i < columnStates.size(); i++) {
            if (i == prevIndex)
                continue;

            string currState = columnStates[i];
            bool valid = true;

            // Loop to iterate over current state and prevState to avoid
            // adjacent matching problem
            for (int j = 0; j < m; j++) {
                if (prevState[j] == currState[j]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                ways = (ways + solve(remainingColumns - 1, i, m)) % M;
            }
        }
        return t[remainingColumns][prevIndex] = ways;
    }

    int colorTheGrid(int m, int n) {
        // Step-1: Generate Column states
        generateColumnStates("", '#', 0, m);

        int totalStates = columnStates.size();
        t = vector<vector<int>>(n + 1, vector<int>(totalStates + 1, -1));

        int result = 0;
        for (int i = 0; i < columnStates.size(); i++) {
            result = (result + solve(n - 1, i, m)) % M;
        }

        return result;
    }
};