/*
 *
 * [2071] Maximum Number of Tasks You Can Assign
 *
 * You have n tasks and m workers. Each task has a strength requirement stored in a 0-indexed integer array tasks, with the ith task requiring tasks[i] strength to complete. The strength of each worker is stored in a 0-indexed integer array workers, with the jth worker having workers[j] strength. Each worker can only be assigned to a single task and must have a strength greater than or equal to the task's strength requirement (i.e., workers[j] >= tasks[i]).
Additionally, you have pills magical pills that will increase a worker's strength by strength. You can decide which workers receive the magical pills, however, you may only give each worker at most one magical pill.

Given the 0-indexed integer arrays tasks and workers and the integers pills and strength, return the maximum number of tasks that can be completed.



Example 1:
Input: tasks = [3,2,1], workers = [0,3,3], pills = 1, strength = 1
Output: 3
Explanation:
We can assign the magical pill and tasks as follows:
- Give the magical pill to worker 0.
- Assign worker 0 to task 2 (0 + 1 >= 1)
- Assign worker 1 to task 1 (3 >= 2)
- Assign worker 2 to task 0 (3 >= 3)

Example 2:
Input: tasks = [5,4], workers = [0,0,0], pills = 1, strength = 5
Output: 1
Explanation:
We can assign the magical pill and tasks as follows:
- Give the magical pill to worker 0.
- Assign worker 0 to task 0 (0 + 5 >= 5)

Example 3:
Input: tasks = [10,15,30], workers = [0,10,10,10,10], pills = 3, strength = 10
Output: 2
Explanation:
We can assign the magical pills and tasks as follows:
- Give the magical pill to worker 0 and worker 1.
- Assign worker 0 to task 0 (0 + 10 >= 10)
- Assign worker 1 to task 1 (10 + 10 >= 15)
The last pill is not given because it will not make any worker strong enough for the last task.
 *
 *
 */
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
public:
    int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills, int strength)
    {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int n = tasks.size(), m = workers.size();

        auto canAssign = [&](int k)
        {
            multiset<int> availableWorkers;
            for (int i = m - k; i < m; ++i)
                availableWorkers.insert(workers[i]);

            int remainingPills = pills;

            for (int i = k - 1; i >= 0; --i)
            {
                int taskStrength = tasks[i];

                auto it = availableWorkers.lower_bound(taskStrength);
                if (it != availableWorkers.end())
                {
                    availableWorkers.erase(it);
                }
                else
                {
                    it = availableWorkers.lower_bound(taskStrength - strength);
                    if (it == availableWorkers.end() || remainingPills == 0)
                        return false;
                    availableWorkers.erase(it);
                    remainingPills--;
                }
            }
            return true;
        };

        int low = 0, high = min(n, m), ans = 0;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (canAssign(mid))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return ans;
    }
};
