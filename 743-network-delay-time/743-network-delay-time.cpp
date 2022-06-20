class Solution {
    typedef pair<int, int> pi;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pi> adj[n+1];
        for (auto &node : times) {
            int u = node[0];
            int v = node[1];
            int t = node[2];
            adj[u].push_back({v, t});
        }
        // Dijstra 
        // <TIME , NODE>
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        unordered_set<int> visited;
        pq.push({0, k});
        int mnTime = 0;  
        while (!pq.empty()) {
            auto f = pq.top();
            int time = f.first;
            int node = f.second;
            pq.pop();
            if (visited.find(node) != visited.end())
                continue;
            mnTime = max(mnTime, time);
            visited.insert(node);
            for (auto &nei : adj[node]) {
                int node = nei.first;
                int time = nei.second;
                if (visited.find(node) != visited.end())
                    continue;
                pq.push({time + mnTime, node});
            }
        }
        return visited.size() == n ? mnTime : -1; 
    }
};