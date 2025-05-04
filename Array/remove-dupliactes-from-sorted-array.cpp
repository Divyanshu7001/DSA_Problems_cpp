/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start

// My Approach
//  class Solution
//  {
//  public:
//      int removeDuplicates(vector<int> &nums)
//      {
//          if (nums.size() == 0)
//          {
//              return 0;
//          }
//          if (nums.size() == 1)
//          {
//              return 1;
//          }
//          unordered_map<int, int> store;
//          int i=0;
//          while (i < nums.size())
//          {
//              if (store.find(nums[i]) == store.end())
//              {
//                  store[nums[i]] = nums[i];
//                  i++;
//              }
//              else
//              {
//                  nums.erase(nums.begin() + i);
//              }
//          }
//          return nums.size();
//      }
//  };

#include <iostream>
#include <vector>
using namespace std;

// two Pointer Approach
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;

        int j = 1; // position to insert next unique value
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
            {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};

// @lc code=end
