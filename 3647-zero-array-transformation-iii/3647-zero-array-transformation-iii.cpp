// Sort the queries
// difference array tracking and updated accordingly
// priority queue for adding which operations have been used in order
// Greedy approach as we are going for minimum return
// If no return...return -1
// else count total-count

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int sz = queries.size();

        sort(queries.begin(), queries.end());

        vector<int> diff(n + 1, 0);
        int sum = 0;
        int j = 0; // To keep track of what may be the next query index
        int count =
            0; // To keep track of how many queries till now to return at last

        priority_queue<int> pq;

        // Looping
        for (int i = 0; i < n; i++) {
            while (j < sz && queries[j][0] <= i) {
                pq.push(queries[j][1]);
                j++;
            }

            while (sum + diff[i] < nums[i]) {
                if (pq.empty())
                    return -1;

                int a = pq.top();
                pq.pop();

                if (a >= i) {
                    diff[i]++;
                    diff[a + 1]--;
                    count++;
                }

            }
            sum += diff[i];
        }

        return sz - count;
    }
};