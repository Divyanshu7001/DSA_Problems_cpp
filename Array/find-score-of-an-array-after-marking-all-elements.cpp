/*
 * [2593] Find Score of an Array After Marking All Elements
 *
 * You are given an array nums consisting of positive integers.
Starting with score = 0, apply the following algorithm:
Choose the smallest integer of the array that is not marked. If there is a tie, choose the one with the smallest index.
Add the value of the chosen integer to score.
Mark the chosen element and its two adjacent elements if they exist.
Repeat until all the array elements are marked.
Return the score you get after applying the above algorithm.


Example 1:
Input: nums = [2,1,3,4,5,2]
Output: 7
Explanation: We mark the elements as follows:
- 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,1,3,4,5,2].
- 2 is the smallest unmarked element, so we mark it and its left adjacent element: [2,1,3,4,5,2].
- 4 is the only remaining unmarked element, so we mark it: [2,1,3,4,5,2].
Our score is 1 + 2 + 4 = 7.


Example 2:
Input: nums = [2,3,5,1,3,2]
Output: 5
Explanation: We mark the elements as follows:
- 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,3,5,1,3,2].
- 2 is the smallest unmarked element, since there are two of them, we choose the left-most one, so we mark the one at index 0 and its right adjacent element: [2,3,5,1,3,2].
- 2 is the only remaining unmarked element, so we mark it: [2,3,5,1,3,2].
Our score is 1 + 2 + 2 = 5.
 *
 *
 */

// Brute force approach
// search for the smallest unmarked element, add its value to the score, and mark its adjacent elements.
// Fails for a very big input value
// T.c=O(n2)
// class Solution {
// public:
//     long long findScore(vector<int>& nums) {

//     int n = nums.size();
//     vector<bool> marked(n, false);
//     long long score = 0;

//     while (true) {
//         int minVal = INT_MAX;
//         int minIdx = -1;

//         // Find the smallest unmarked element (with smallest index in case of tie)
//         for (int i = 0; i < n; ++i) {
//             if (!marked[i] && nums[i] < minVal) {
//                 minVal = nums[i];
//                 minIdx = i;
//             }
//         }

//         // No unmarked elements left
//         if (minIdx == -1)
//             break;

//         // Add to score
//         score += nums[minIdx];

//         // Mark the element and its adjacent elements
//         marked[minIdx] = true;
//         if (minIdx > 0) marked[minIdx - 1] = true;
//         if (minIdx < n - 1) marked[minIdx + 1] = true;
//     }
//     return score;
//     }
// };

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// Optimal approach with min-heap and boolean vector of marked index
// put the {value,index} pair in min-heap
// keep popping the min values from the heap top
// if the index of boolean vector marked already..skip
// if not marked..the the index..and adjacent indexes...mark them as true in the bool vector
// keep repeating until done
class Solution
{
public:
    long long findScore(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> marked(n, false); // Track marked elements

        // Min-heap: stores (value, index)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        // Populate heap with all (value, index) pairs
        for (int i = 0; i < n; ++i)
        {
            minHeap.emplace(nums[i], i);
        }

        long long score = 0;

        while (!minHeap.empty())
        {
            auto [val, idx] = minHeap.top();
            minHeap.pop();

            // Skip if already marked
            if (marked[idx])
                continue;

            // Add value to score
            score += val;

            // Mark current and adjacent indices
            marked[idx] = true;
            if (idx > 0)
                marked[idx - 1] = true;
            if (idx < n - 1)
                marked[idx + 1] = true;
        }

        return score;
    }
};

