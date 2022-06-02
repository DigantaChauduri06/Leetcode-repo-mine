// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
   bool check_BFS(vector<int> adj[],int sv,vector<bool> &vis) {
    queue<pair<int,int>> q;
    q.push({sv,-1});
    vis[sv] = true;
    while (!q.empty()) {
        int size =q.size();
        while (size--) {
            auto f = q.front();
            q.pop();
            int prev = f.second;
            int curr = f.first;
            for (auto &node : adj[curr]) {
                if (!vis[node]) {
                    q.push({node,curr});
                    vis[node] = true;
                }
                else {
                    if (prev != node) return true;
                }
            }
        }
    }
    return false;
    
}
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
    
            vector<bool> vis(V,false);
    for (int i = 0;i < V;i++) {
        if (!vis[i] && check_BFS(adj,i,vis)) return true;
    }
    return false;
}

};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends