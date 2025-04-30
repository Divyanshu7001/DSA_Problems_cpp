/*
 *
 * [75] Sort Colors
 *
 * Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.



Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]

 *
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// // Doesnt work..as the map keys cant be sorted
// class Solution
// {
// public:
//     void sortColors(vector<int> &nums)
//     {
//         unordered_map<int, int> store;
//         vector<int> ans;
//         for (auto &i : nums)
//         {
//             if (store.find(i) == store.end())
//             {
//                 store[i] = 1;
//             }
//             else
//             {
//                 store[i] += 1;
//             }
//         }

//         for (auto &pair : store)
//         {
//             int i = 1;
//             // cout << pair.second << endl;
//             while (i <= pair.second)
//             {
//                 // cout << pair.first << " & " << pair.second<<endl;
//                 ans.push_back(pair.first);
//                 i++;
//             }
//         }

//         for (auto &i : ans)
//         {
//             cout << i << " ";
//         }
//     }
// };

// optimized solution
// Three pointers..iterate and increase
// take an independent var to have the index which keeps increasing as the elements are modified
// now while the counters isnt 0..keep updating index
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int count0 = 0, count1 = 0, count2 = 0;

        for (int num : nums)
        {
            if (num == 0)
                count0++;
            else if (num == 1)
                count1++;
            else
                count2++;
        }

        int i = 0;
        while (count0--)
            nums[i++] = 0;
        while (count1--)
            nums[i++] = 1;
        while (count2--)
            nums[i++] = 2;

        for (auto &i : nums)
        {
            cout << i << " ";
        }
    }
};

int main()
{
    vector<int> v = {2, 0, 2, 1, 1, 0};
    Solution solution;
    solution.sortColors(v);
    cout << endl;
}
