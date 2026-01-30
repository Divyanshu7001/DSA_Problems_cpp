class Solution {
public:
    typedef long long ll;
    typedef pair<ll, string> P;

    ll BIG_VALUE = 1e10;
    unordered_map<string, vector<pair<string, ll>>> adj; // Graph

    unordered_map<string, unordered_map<string, ll>> dijikstraMemo;
    vector<ll> dpMemo;

    string sourceStr, targetStr;
    set<int> validLengths;

    ll dijikstra(string& start, string& end) {
        if (dijikstraMemo[start].count(end))
            return dijikstraMemo[start][end];
        //{cost,string}
        priority_queue<P, vector<P>, greater<P>> pq;

        unordered_map<string, ll>
            result; // cost of going from source string to target string

        result[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            ll currCost = pq.top().first;
            string node = pq.top().second;
            pq.pop();

            if (node == end)
                break;

            for (auto& edge : adj[node]) {
                string adjNode = edge.first;
                ll edgeCost = edge.second;

                if (!result.count(adjNode) ||
                    currCost + edgeCost < result[adjNode]) {
                    result[adjNode] = currCost + edgeCost;
                    pq.push({currCost + edgeCost, adjNode});
                }
            }
        }

        ll finalCost = result.count(end) ? result[end] : BIG_VALUE;

        return dijikstraMemo[start][end] = finalCost;
    }

    ll solve(int idx) {
        if (idx == sourceStr.length())
            return 0;

        if (dpMemo[idx] != -1)
            return dpMemo[idx];

        ll minCost = BIG_VALUE;

        if (sourceStr[idx] == targetStr[idx])
            minCost = solve(idx + 1);

        for (auto& length : validLengths) {
            if (idx + length > sourceStr.length())
                break;

            string strSub = sourceStr.substr(idx, length);
            string targetSub = targetStr.substr(idx, length);

            if (!adj.count(strSub))
                continue;

            ll minPathCost = dijikstra(strSub, targetSub);
            if (minPathCost == BIG_VALUE)
                continue;

            minCost = min(minCost, minPathCost + solve(idx + length));
        }

        return dpMemo[idx] = minCost;
    }

    long long minimumCost(string source, string target,
                          vector<string>& original, vector<string>& changed,
                          vector<int>& cost) {

        sourceStr = source, targetStr = target;

        dpMemo.assign(10001, -1);

        for (int i = 0; i < original.size(); i++) {
            adj[original[i]].push_back({changed[i], cost[i]});
        }

        for (auto& s : original)
            validLengths.insert(s.length());
        ll result = solve(0);

        return result == BIG_VALUE ? -1 : result;
    }
};