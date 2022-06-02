// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
   bool check_BFS(vector<int> adj[], int sv,unordered_set<int> &st) {
        // Code here
        queue<pair<int,int>> q;
        q.push({sv,-1});
        st.insert(sv);
        while (!q.empty()) {
            auto parent = q.front();
            q.pop();
            int cur = parent.first;
            int prev = parent.second;
            for (auto &child : adj[cur]) {
                if (st.find(child) == st.end()) {
                    // cout << parent << ":" << child << endl;
                    q.push({child, cur});
                    st.insert(child);
                } else {
                    if (prev != child) {
                        // cout << parent << ":" << child << endl;
                        return 1;
                    }
                }
            }
        }
        return false;
    }
public:
     bool isCycle(int V, vector<int> adj[]) {
        // Code here
    unordered_set<int> st;
    for (int i = 0;i < V;i++) {
        if (st.find(i) == st.end() && check_BFS(adj,i,st)) return true;
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