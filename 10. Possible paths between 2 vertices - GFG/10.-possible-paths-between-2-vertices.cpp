// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
        unordered_set<int> visited;
        unordered_set<int> all;
        int count = 0;
  public:
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int s, int d) {
        // Code here

        bfs(adj, s, d, V);
        // dfs(adj, s, d);
        return count; 
    }
private:
    void bfs(vector<int> adj[], int s, int d,int V) {
        queue<int> q;
        q.push(s);
        if (s == d) {
            count++;
            return;
        }
        visited.insert(s);
        while (q.size() != 0) {
            int f = q.front();
            q.pop();
            for (auto &node : adj[f]) {
                if (node == d) {
                    count++;
                    continue;
                }
                // if (visited.find(node) == visited.end()) {
                    q.push(node);
                // }
            }
        }
    }
    void dfs(vector<int> adj[], int s, int d) {
        if (s == d) {
            count++;
            return;
        }
        if (s != d)
            visited.insert(s);
        for (auto &node : adj[s]) {
            if (node == d) {
                count++;
                continue;
            }
            if (visited.find(node) == visited.end()) {
                dfs(adj, s, d);
            }
        }
        
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
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}  // } Driver Code Ends