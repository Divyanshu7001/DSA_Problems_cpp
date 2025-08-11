// Logic of building powers vector
// In the binary representation of any number , the set bits should be added to
// the powers vector Do the binary represenation & keep checking which bits are
// set..the set bits should be added to the powers
// T.c=O(Qâ32) = O(Q)
class Solution {
public:
    void buildPowers(int n, vector<int>& powers) {
        for (int i = 0; i < 32; i++) {
            if ((n & (1 << i)) != 0)
                powers.push_back(1 << i);
        }
    }
    int MOD = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        vector<int> answers;
        buildPowers(n, powers);
        for (auto &query:queries) {
            int startingPoint = query[0], endingPoint = query[1];
            long multipliedValue = 1;
            for (int j = startingPoint; j <= endingPoint; j++) {
                multipliedValue = (multipliedValue * powers[j]) % MOD;
            }
            answers.push_back(multipliedValue);
        }
        return answers;
    }
};

// T.c=O(QâN)
// Gives TLE in bigger inputs and out of index
//  class Solution {
//  public:
//      void buildPowers(int n, vector<int>& powers) {
//          if (n == 0)
//              return;
//          int previous = 1;
//          for (int i = 2; i <= 1e9; i <<= 1) {
//              if (i == n) {
//                  powers.push_back(i);
//                  return;
//              } else if (i < n) {
//                  previous = i;
//              } else if (i > n) {
//                  powers.push_back(previous);
//                  buildPowers(n - previous, powers);
//                  return;
//              }
//          }
//      }
//      vector<int> productQueries(int n, vector<vector<int>>& queries) {
//          vector<int> powers;
//          buildPowers(n, powers);
//          sort(powers.begin(), powers.end());
//          const int MOD = 1000000007;
//          vector<int> answers;
//          int sz = queries.size();
//          for (int i = 0; i < sz; i++) {
//              int startingPoint = queries[i][0], endingPoint = queries[i][1];
//              int multipliedValue = 1;
//              for (int j = startingPoint; j <= endingPoint; j++) {
//                  multipliedValue = (1LL * multipliedValue * powers[j]) % MOD;
//              }
//              answers.push_back(multipliedValue);
//          }
//          return answers;
//      }
//  };