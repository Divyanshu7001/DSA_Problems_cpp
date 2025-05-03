/*
 *
 * [1007] Minimum Domino Rotations For Equal Row
 *
 * In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)
   We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.
   Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.
   If it cannot be done, return -1.

   Example 1:
   Input: tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
   Output: 2
   Explanation:
   The first figure represents the dominoes as given by tops and bottoms: before we do any rotations.
   If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.

   Example 2:
   Input: tops = [3,5,1,2,3], bottoms = [3,6,3,3,4]
   Output: -1
   Explanation:
   In this case, it is not possible to rotate the dominoes to make one row of values equal
 *
 */

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int getMinRotations(int target, vector<int> &tops, vector<int> &bottoms)
    {
        int topSwaps = 0, bottomSwaps = 0;
        int n = tops.size();

        for (int i = 0; i < n; i++)
        {
            if (tops[i] != target && bottoms[i] != target)
            {
                return -1;
            }

            else if (tops[i] != target)
            {
                topSwaps++;
            }

            else if (bottoms[i] != target)
            {
                bottomSwaps++;
            }
        }

        return min(topSwaps, bottomSwaps);
    }

    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        // tops[0] as the target
        int rotations = getMinRotations(tops[0], tops, bottoms);

        if (rotations != -1 || tops[0] == bottoms[0])
        {
            return rotations;
        }

        // bottoms[0] as the target
        return getMinRotations(bottoms[0], tops, bottoms);
    }
};

int main()
{
    vector<int> tops = {2, 1, 2, 4, 2, 2};
    vector<int> bottom = {5, 2, 6, 2, 3, 2};

    Solution sol;
    int res = sol.minDominoRotations(tops, bottom);
    cout << res << endl;
}