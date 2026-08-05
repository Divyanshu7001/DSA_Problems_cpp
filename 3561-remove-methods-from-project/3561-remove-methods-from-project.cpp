// process:
// have to make a indegree array for the nodes
// then do a dfs from the marked kth node...keep going forward and mark the
// reachable nodes as suspicious & update their indegree accordingly then see if
// any node marked suspicious still has >0 indegree..if yes..return whole
// input..else remove the suspicious nodes and return
class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);
        for (vector<int>& p : invocations) {
            adj[p[0]].push_back(p[1]);
            indegree[p[1]]++;
        }
        vector<bool> suspicious(n, false);
        queue<int> que;
        que.push(k);
        suspicious[k]=true;

        while (!que.empty()) {
            int curr = que.front();
            que.pop();
            for (int& ngbr : adj[curr]) {
                indegree[ngbr]--;
                if (!suspicious[ngbr]) {
                    que.push(ngbr);
                    suspicious[ngbr] = true;
                }
            }
        }

        vector<int> res;
        bool cannotRemove = false;
        for (int i = 0; i < n; i++) {
            if (suspicious[i] && indegree[i] > 0) {
                cannotRemove = true;
                break;
            }

            if (!suspicious[i])
                res.push_back(i);
        }

        if (cannotRemove) {
            vector<int> res(n);
            for (int i = 0; i < n; i++)
                res[i] = i;

            return res;
        }

        return res;
    }
};