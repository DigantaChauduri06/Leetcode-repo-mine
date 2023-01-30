//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  unordered_set<int> vis;
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        for (int i = 0;i < V;i++) {
            unordered_set<int> dfsVis;
            if (vis.find(i) == vis.end() && hasCycle(adj, i, dfsVis)) return true;
        }
        return false;
    }
private:
    bool hasCycle(vector<int> adj[], int sv, unordered_set<int> &dfsVis) {
        vis.insert(sv);
        dfsVis.insert(sv);
        for (auto &node : adj[sv]) {
            if (vis.find(node) == vis.end()) {
                if (hasCycle(adj, node, dfsVis)) {
                    return true;
                }
            } else if (vis.find(node) != vis.end() && dfsVis.find(node) != dfsVis.end()) {
                return true;
            }
        }
        dfsVis.erase(sv);
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends