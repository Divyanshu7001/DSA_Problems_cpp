// Logic:
// When we divide the polygon by a triangle and remove it..generally we get two
// small polygons from it i.e left + current + right => in the recursive
// function..get the current cut's overall weight then do left polygon recurse
// call + current weightv+ right recurse call => result
class Solution {
public:
    //T.C=O(n3)
    int t[51][51];
    //O(n2) as we can at most visit n2 states as the size of the array taken is (n+1)(n+1)
    int solve(vector<int>& values, int i, int j) {

        // suppose {a,b,c,d,e,f}
        // if by triangulating we get to set position where i=a & j=b
        // we cant triangulate anymore as we need at least 3 points to do so

        if (j - i + 1 < 3)
            return 0;

        if (t[i][j] != -1)
            return t[i][j];

        int result = INT_MAX;

        for (int k = i + 1; k < j; k++) {//O(n)
            int wt = values[i] * values[k] * values[j] + solve(values, i, k) +
                     solve(values, k, j);

            result = min(result, wt);
        }

        return t[i][j] = result;
    }

    int minScoreTriangulation(vector<int>& values) {

        int n = values.size();
        if (n == 3)
            return values[0] * values[1] * values[2];
        memset(t, -1, sizeof(t));
        
        return solve(values, 0, n - 1);
    }
};