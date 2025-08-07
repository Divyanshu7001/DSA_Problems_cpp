class Solution {
public:
    bool isPossible(int x, int y, int n) {
        // make sure the given range lies in the upper traingular matrix
        if (y >= x && x >= 0 && x < n && y >= 0 && y < n) {
            return true;
        }
        return false;
    }

    int maxScore(vector<vector<int>>& fruits) {
        int n = fruits.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp = fruits;

        //for 2*2 matrix..2nd just just need to add the starting point
        if(n==2) return dp[0][n-1];
        //for 3*3 matrix..2nd guy just needs to add starting & just under its position
        if(n==3) return dp[0][n-1]+dp[1][n-1];

        //For 4*4 & more
        // For the second child
        // he actually have to reach upto (n-2,n-1) as 1st child already taken
        // the (n-1,n-1) room fruits
        for (int i = n - 2; i > 1; i--) {
            for (int j = i + 1; j < n; j++) {
                // (i,j) => possible steps that this can go if they are not
                // empty
                //(i-1,j-1) (i-1,j) (i-1,j+1)

                int x = i - 1;
                for (int y = j - 1; y <= j + 1; y++) {
                    if (isPossible(x, y, n)) {
                        dp[x][y] = max(dp[x][y], fruits[x][y] + dp[i][j]);
                    }
                }
            }
        }

        return fruits[0][n-1] + max(dp[1][n-2],dp[1][n-1]);
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size(), ans = 0;
        // for 1st child...to go to last room i.e (n-1),(n-1) .. he can only
        // move diagonal wise..otheriwse it is not possible
        for (int i = 0; i < n; i++) {
            ans += fruits[i][i];
        }

        //Get and add the fruits collected by the second child
        ans+=maxScore(fruits);

        //For third child...it is actually right at the opposite end of second having just the opposite conditions of traversal
        //Just trasnpose the matrix & add the swapped / opposite result that we got from 2nd child
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(fruits[i][j],fruits[j][i]);
            }
        }
        //After transpose of matrix..just call the function again to add to the score
        //here third child behaves like second with opposite values
        ans+=maxScore(fruits);

        return ans;
    }
};