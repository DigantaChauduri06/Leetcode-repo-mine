// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
    int find_parent(int a, int par[]) {
        if (par[a] == a) return a;
        return par[a] = find_parent(par[a], par);
    }
    bool isCycle(int a, int b, int par[], int rank[]) {
        //code here
        int par_a = find_parent(a, par);
        int par_b = find_parent(b, par);
        
        if (par_a == par_b) return true;
        
        if (rank[par_a] > rank[par_b]) {
            par[par_b] = par_a;
        } else if (rank[par_a] < rank[par_b]) {
            par[par_a] = par_b;
        } else {
            par[par_a] = par_b;
            rank[par_b]++;
        }
        return false;
    }
	int detectCycle(int V, vector<int>adj[]) {
	    // Code here
	    int rank[V], par[V];
	    for (int i = 0;i < V;i++) {
	        par[i] = i;
	        rank[i] = 1;
	    }
	    for (int i = 0;i < V;i++) {
	        for (auto &it : adj[i]) {
	            if (it >= i)
	                if (isCycle(it, i, par, rank)) return true;
	        }
	    }
	    return false;
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
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}  // } Driver Code Ends