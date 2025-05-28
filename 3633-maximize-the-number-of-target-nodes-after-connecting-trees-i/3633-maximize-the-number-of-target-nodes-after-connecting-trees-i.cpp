class Solution {
public:
    // BFS
    // int bfs(int curr, unordered_map<int, vector<int>> adj, int d, int N) {
    //     queue<pair<int, int>> que;
    //     que.push({curr, 0});
    //     vector<bool> visited(N, false);

    //     visited[curr] = true;

    //     int count = 0; // Count of target node
    //     while (!que.empty()) {
    //         int currNode = que.front().first;
    //         int dist = que.front().second;
    //         que.pop();

    //         if (dist > d) {
    //             continue;
    //         }

    //         count++; // Current node count included in count

    //         // Visit neighbours
    //         for (auto &ngbr : adj[currNode]) {
    //             if (!visited[ngbr]) {
    //                 visited[ngbr] = true;
    //                 que.push({ngbr, dist + 1});
    //             }
    //         }
    //     }

    //     return count;
    // }

    // DFS
    // int dfs(int curr, unordered_map<int, vector<int>> adj, int d,
    //         int currentNodeParent) {
    //     if (d < 0) {
    //         return 0;
    //     }

    //     int count = 1; // counting current node as 1

    //     for (int& ngbr : adj[curr]) {
    //         if (ngbr != currentNodeParent) {
    //             count += dfs(ngbr, adj, d - 1, curr);
    //         }
    //     }

    //     return count;
    // }
    int dfs_iterative(int start, unordered_map<int, vector<int>>& adj, int d) {
        stack<pair<int, int>> st; // {node, remaining depth}
        unordered_set<int> visited;
        st.push({start, 0});
        visited.insert(start);

        int count = 0;
        while (!st.empty()) {
            auto [node, dist] = st.top();
            st.pop();

            if (dist > d)
                continue;

            count++;

            for (int& ngbr : adj[node]) {
                if (!visited.count(ngbr)) {
                    visited.insert(ngbr);
                    st.push({ngbr, dist + 1});
                }
            }
        }
        return count;
    }

    vector<int> findCount(vector<vector<int>>& edges, int d) {
        int N = edges.size() + 1;

        // adjacency list
        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> result(N);
        for (int i = 0; i < N; ++i) {
            // result[i] = bfs(i, adj, d, N);
            // result[i] = dfs(i, adj, d, -1);
            result[i] = dfs_iterative(i, adj, d);
        }

        return result;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        // Total nodes in tree 1
        int N = edges1.size() + 1;

        vector<int> result1 =
            findCount(edges1, k); // Storing target Nodes count from each node
                                  // within tree1 within k distance
        vector<int> result2 = findCount(
            edges2, k - 1); // Storing the target nodes count from each node
                            // within tree2 within k-1 distance

        int maxTargetNodesCount = *max_element(begin(result2), end(result2));

        for (int i = 0; i < result1.size(); i++) {
            result1[i] += maxTargetNodesCount;
        }

        return result1;
    }
};