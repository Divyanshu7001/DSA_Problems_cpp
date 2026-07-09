//making out component numbers from diff of nodes and maxDiff value diff..if satisfies condition, then same component
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
       vector<int>component(n,-1);
        int compID=0;
        component[0]=compID;

        for (int i = 1; i < n; i++) {
            if(abs(nums[i]-nums[i-1])>maxDiff)
                compID++;
            component[i]=compID;
        }

        vector<bool>res;
        for(auto& query:queries){
            int u=query[0],v=query[1];
            res.push_back(component[u]==component[v]);
        }
        
        return res;
    }
};


//BFS + HASH-TABLE => TLE
// class Solution {
// public:
//     vector<bool> res;

//     void solve(unordered_map<int, vector<int>>& adj,
//                vector<vector<int>>& queries) {

//         for (auto& query : queries) {
//             int start = query[0], end = query[1];
//             unordered_set<int> visited;
//             queue<int> que;

//             que.push(start);
//             visited.insert(start);

//             bool result = false;
//             while (!que.empty()) {
//                 int node = que.front();
//                 que.pop();
//                 if (node == end) {
//                     result = true;
//                     break;
//                 }
//                 for (int nei : adj[node]) {
//                     if (!visited.count(nei)) {
//                         visited.insert(nei);
//                         que.push(nei);
//                     }
//                 }
//             }

//             res.push_back(result);
//         }
//     }

//     vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
//                                       vector<vector<int>>& queries) {
//         unordered_map<int, vector<int>> adj;

//         for (int i = 0; i < n; i++) {
//             int j = i + 1;
//             while (j < n) {
//                 if (abs(nums[j] - nums[i]) <= maxDiff) {
//                     adj[i].push_back(j);
//                     adj[j].push_back(i);
//                     j++;
//                 } else
//                     break;
//             }
//         }

//         solve(adj, queries);
//         return res;
//     }
// };