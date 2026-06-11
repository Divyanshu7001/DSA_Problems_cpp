class Solution {
public:
    typedef long long ll;
    int M = 1e9 + 7;

    ll power(ll base, ll exp) {
        if (exp == 0)
            return 1;

        ll half = power(base, exp / 2);
        ll res = (half * half) % M;
        if (exp % 2 == 1)
            res = (res * base) % M;

        return res;
    }

    int getDepth(unordered_map<int, vector<int>>& adj, int node, int parent) {
        int depth = 0;

        for (int& ngbr : adj[node]) {
            if (ngbr == parent)
                continue;

            depth = max(depth, getDepth(adj, ngbr, node) + 1);
        }

        return depth;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        // Building adj list
        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int n = getDepth(adj, 1, -1);
        return power(2, n - 1);
    }
};