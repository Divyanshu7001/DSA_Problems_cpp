/*
 *
 * [442] Find All Duplicates in an Array
 *
 * Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output

Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]

Example 2:
Input: nums = [1,1,2]
Output: [1]

Example 3:
Input: nums = [1]
Output: []
 *
 *
 *
 */

// Only beats 30% solution and very slow
//  class Solution
//  {
//  public:
//      vector<int> findDuplicates(vector<int> &nums)
//      {
//          vector<int> ans;
//          unordered_map<int, int> store;
//          for (auto &i : nums)
//          {
//              if (store.find(i) == store.end())
//              {
//                  store[i] = 1;
//              }
//              else
//                  ans.push_back(i);
//          }

//         store.clear();

//         return ans;
//     }
// };

// Get the the index value by absolute value of the vector index -1 due to size and indexing
// if we havent visited the index value of te vector before..make it negative
// if that index value is already negative..push in vector as it is duplicate
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> ans;

        for (auto &i : nums)
        {
            int idx = abs(i) - 1;

            if (nums[idx] < 0)
                ans.push_back(abs(i));
            else
                nums[idx] = -nums[idx];
        }

        return ans;
    }
};
