/*
 *
 * [442] Find All Duplicates in an Array
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
