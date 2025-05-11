/*
 * @lc app=leetcode id=1550 lang=cpp
 *
 * [1550] Three Consecutive Odds
 *
 * Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.

Example 1:
Input: arr = [2,6,4,1]
Output: false
Explanation: There are no three consecutive odds.

Example 2:
Input: arr = [1,2,34,3,4,5,7,23,12]
Output: true
Explanation: [5,7,23] are three consecutive odds.
 *
 *
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        int count = 0;
        bool prevOdd = false;
        for (auto &num : arr)
        {
            if (num % 2 != 0)
            {
                count += 1;
                prevOdd = true;
            }
            else
            {
                if (prevOdd == true)
                {
                    prevOdd = false;
                    count = 0;
                }
            }
            if (count == 3)
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
