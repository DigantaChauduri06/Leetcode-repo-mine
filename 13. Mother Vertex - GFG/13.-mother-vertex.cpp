// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[]) {
	    // Code here
	    for (int i = 0;i < V;i++) {
	        if (bfs(adj, i, V)) {
	            return i;
	        }
	    }
	    return -1;
	}
private:
    bool bfs(vector<int> adj[],int i, int V) {
        int cnt = 0;
        queue<int> q;
        q.push(i);
        vector<int> vec(V, 0);
        vec[i] = 1;
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            cnt++;
            for (auto &node : adj[f]) {
                if (!vec[node]) {
                    vec[node] = 1;
                    q.push(node);
                }
            }
        }
        return cnt == V;
    }

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends