class Solution {
    typedef pair<int, int> pi;
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pi, vector<pi>, greater<pi>> frontTier;
        int V = size(points);
        vector<pair<int, int>> adj[V];
        unordered_set<int> seen;
        // Make adj list
        for (int i = 0;i < V;i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i+1;j < V;j++) {
                int x2 = points[j][0], y2 = points[j][1];
                int cost = distance(x1, y1, x2, y2);
                adj[i].push_back({cost, j});
                adj[j].push_back({cost, i});
            }
        }
        // Prims algo
        frontTier.push({0, 0});
        int cur_cost = 0;
        // seen.insert(0);
        while (seen.size() < V) {
            auto front = frontTier.top();
            frontTier.pop();
            if (seen.find(front.second) != seen.end()) continue;
            seen.insert(front.second);
            cur_cost += front.first;
            for (auto &node : adj[front.second]) {
                if (seen.find(node.second) == seen.end()) {
                    frontTier.push(node);
                    // seen.insert(node.second);
                }
            }
        }
        return cur_cost;
    }
private:
    int distance(int &x1, int &y1, int &x2, int &y2) {
        return abs(x1 - x2) + abs(y1 - y2);
    }
};