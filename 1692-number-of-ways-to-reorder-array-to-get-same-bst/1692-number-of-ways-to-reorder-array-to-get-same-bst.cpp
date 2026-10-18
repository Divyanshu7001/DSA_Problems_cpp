// By Observation:
// the root i.e the first node of the original array must be kept at the same
// place fixed for all the reorders..to even have a chance of building the same
// bst && the relative order of left and right supposed nodes have to be same
// for the other nodes..
// lets say..to build the left subtree..the left nodes have to be called in a
// recursion X times alike, for the right subtree..right nodes have to be called
// in a recursion Y times And given that the total calls for both sides for one
// reorder check.. x*y no given that for the total reorders of whole array
// ..that will happen approx Z times i.e total Z*(X*Y) times.

// Now,
// to get the Z = i.e other nodes(n-1) being placed at (n-1)spots => (n-1)C(L)
// i.e no of ways to placed left nodes(L) at the (n-1) spots or we can do
// (n-1)C(R) for right nodes.

// Now,
// doing ncr everytime is not optimal
// so to do ncr optimally, pascal's triangle have to be used.

// Approach (Combinatorics and Pascal's Triangle)
// T.C : O(n^2)
// S.C : O(n^2)
class Solution {
public:
    typedef long long ll;
    ll MOD = 1e9 + 7;

    vector<vector<ll>> PT;

    int solve(vector<int>& nums) {
        int m = nums.size();

        if (m < 3)
            return 1;

        vector<int> left, right;

        int root = nums[0];
        for (int i = 1; i < m; i++) {

            if (nums[i] < root) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        ll leftways = solve(left) % MOD;
        ll rightways = solve(right) % MOD;

        return (((leftways * rightways) % MOD) * PT[m - 1][left.size()]) % MOD;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        PT.resize(n + 1);

        for (int i = 0; i <= n; i++) {

            PT[i] = vector<long long>(i + 1, 1);

            for (int j = 1; j < i; j++) {
                PT[i][j] = (PT[i - 1][j - 1] + PT[i - 1][j]) % MOD;
            }
        }

        return (solve(nums) - 1) % MOD;
    }
};