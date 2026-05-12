// Binary search on answer=>T.C=O(nlogn)
class Solution {
public:
    // Function to check if doing all of the tasks is possible given a possible
    // min energy
    bool isPossible(vector<vector<int>>& tasks, int energy) {
        if (energy < tasks[0][1])
            return false;

        for (auto& task : tasks) {
            if (energy >= task[1]) {
                energy -= task[0];
            } else
                return false;
        }

        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {

        auto lambda = [](auto task1, auto task2) {
            int diff1 = task1[1] - task1[0];
            int diff2 = task2[1] - task2[0];
            return diff1 > diff2;
        };
        // sorting will be done based on the difference of actual and minimum
        // energy of tasks as we wanna do the task having the most remaining
        // first
        sort(tasks.begin(), tasks.end(), lambda);

        int low = 0, high = 1e9, result = INT_MAX;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(tasks, mid)) {
                result = min(result, mid);
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return result;
    }
};