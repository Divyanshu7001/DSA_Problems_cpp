// It actually wants the probability of of reaching more than k & less than or
// on to n probability of reaching n = p(k)+p(k+1)+p(k+2)+....p(n)

// T.C=O(n2)
// T.L.E
//  class Solution {
//  public:
//      double new21Game(int n, int k, int maxPts) {
//          vector<double>dp(n+1); //dp[i] => probability of reaching i at some
//          point dp[0]=1;
//          //dp[i]=dp[i-1]+dp[i-2]+dp[i-3]+....dp[i-maxPts]
//          for(int i=1;i<=n;i++){
//              for(int j=1;j<=maxPts;j++){
//                  //dp[i-j]=>dp[i]
//                  if(i>=j && i-j<k){
//                      dp[i]+=dp[i-j]/maxPts;
//                  }
//              }
//          }

//         double ans=0;
//         for(int i=k;i<=n;i++){
//             ans+=dp[i];
//         }
//         return ans;
//     }
// };

// Sliding window approach with dp
// T.C=O(n)
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k==0)return 1;
        vector<double> dp(
            n + 1); // dp[i] => probability of reaching i at some point
        dp[0] = 1;
        double win = 1;
        // dp[i]=dp[i-1]+dp[i-2]+dp[i-3]+....dp[i-maxPts]
        for (int i = 1; i <= n; i++) {
            dp[i] = win / maxPts;
            if (i < k) { // increment window size until reaching goal of k
                win += dp[i];
            }
            if (i >= maxPts &&
                i - maxPts < k) { // keep decrementing when to encounter
                                  // windowsize of > maxPts
                win -= dp[i - maxPts];
            }
        }

        double ans = 0;
        for (int i = k; i <= n; i++) {
            ans += dp[i];
        }
        return ans;
    }
};