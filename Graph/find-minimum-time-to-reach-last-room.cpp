/*
 *
 * [3341] Find Minimum Time to Reach Last Room I
 *
 * There is a dungeon with n x m rooms arranged as a grid.
You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds when you can start moving to that room. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes exactly one second.
Return the minimum time to reach the room (n - 1, m - 1).
Two rooms are adjacent if they share a common wall, either horizontally or vertically.


[Djikstra's Algorithm used on 2d-array to find the shortest path]


Example 1:
Input: moveTime = [[0,4],[4,4]]
Output: 6
Explanation:
The minimum time required is 6 seconds.
At time t == 4, move from room (0, 0) to room (1, 0) in one second.
At time t == 5, move from room (1, 0) to room (1, 1) in one second.


Example 2:
Input: moveTime = [[0,0,0],[0,0,0]]
Output: 3
Explanation:
The minimum time required is 3 seconds.
At time t == 0, move from room (0, 0) to room (1, 0) in one second.
At time t == 1, move from room (1, 0) to room (1, 1) in one second.
At time t == 2, move from room (1, 1) to room (1, 2) in one second.

Example 3:
Input: moveTime = [[0,1],[1,2]]
Output: 3
 *
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    // Priority queue storage({time,{i,j}})
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    typedef pair<int, pair<int, int>> P;
    int minTimeToReach(vector<vector<int>> &moveTime)
    {
        int m = moveTime.size();
        int n = moveTime[0].size();

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;

        result[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty())
        {
            int currTime = pq.top().first;
            auto cell = pq.top().second;
            int i = cell.first;
            int j = cell.second;

            pq.pop();
            if (i == m - 1 && j == n - 1)
            {
                return currTime;
            }

            for (auto &dir : directions)
            {
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n)
                {
                    int wait = max(moveTime[i_][j_] - currTime, 0);
                    int arrivalTime = currTime + wait + 1;

                    if (result[i_][j_] > arrivalTime)
                    {
                        result[i_][j_] = arrivalTime;
                        pq.push({arrivalTime, {i_, j_}});
                    }
                }
            }
        }
        return -1;
    }
};
