// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
   {
       // Code here
       vector<int> dis(V,INT_MAX);
      queue<pair<int,int>> pq; //dis,node
       dis[S]=0;
       pq.push({0,S});
       while(!pq.empty())
       {
           int node=pq.front().second;
           pq.pop();
           for(auto it:adj[node])
           {
               int nd=it[0];
               int weight=it[1];
               if(weight+dis[node]<dis[nd])
               {
                   dis[nd]=weight+dis[node];
                   pq.push({dis[nd],nd});
               }
           }
       }
       return dis;
   }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends