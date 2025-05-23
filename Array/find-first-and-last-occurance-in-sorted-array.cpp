/*
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findFirst(const vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1, first = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target)
            {
                right = mid - 1;
            }
            if (nums[mid] == target)
                first = mid;
            if (nums[mid] < target)
                left = mid + 1;
        }
        return first;
    }

    int findLast(const vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1, last = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target)
            {
                left = mid + 1;
            }
            if (nums[mid] == target)
                last = mid;
            if (nums[mid] > target)
                right = mid - 1;
        }
        return last;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
        return {first, last};
    }
};
