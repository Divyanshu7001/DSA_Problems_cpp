class Solution {
public:
    vector<vector<int>> getAdj(vector<vector<int>>& edges, int n) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }

    // O(V+E)
    void dfs(int curr, vector<vector<int>>& adj, int parent, vector<int>& mark,
             int& zeroMarkedCountA, int& oneMarkedCountA) {

        if (mark[curr] == 0) {
            zeroMarkedCountA++;
        } else {
            oneMarkedCountA++;
        }

        for (auto& ngbr : adj[curr]) {
            if (ngbr != parent) {
                mark[ngbr] =
                    (mark[curr] == 0) ? 1 : 0; // Alternate 0 and 1 marking
                dfs(ngbr, adj, curr, mark, zeroMarkedCountA, oneMarkedCountA);
            }
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {

        int N = edges1.size() + 1;
        int M = edges2.size() + 1;

        vector<vector<int>> adjA = getAdj(edges1,N);
        vector<vector<int>> adjB = getAdj(edges2,M);

        vector<int> markA(N, -1);
        markA[0] = 0; // mark 0th node as 0
        int zeroMarkedCountA = 0;
        int oneMarkedCountA = 0;

        dfs(0, adjA, -1, markA, zeroMarkedCountA, oneMarkedCountA); // O(V+E)

        vector<int> markB(M, -1);
        markB[0] = 0; // mark 0th node as 0
        int zeroMarkedCountB = 0;
        int oneMarkedCountB = 0;

        dfs(0, adjB, -1, markB, zeroMarkedCountB, oneMarkedCountB); // O(V+E)

        int maxFromTree2 = max(zeroMarkedCountB, oneMarkedCountB);
        vector<int> result(N);
        for (int i = 0; i < N; i++) { // O(V)
            int marking = markA[i];
            if (marking == 0) {
                result[i] = zeroMarkedCountA + maxFromTree2;
            } else {
                result[i] = oneMarkedCountA + maxFromTree2;
            }
        }

        return result;
    }
};