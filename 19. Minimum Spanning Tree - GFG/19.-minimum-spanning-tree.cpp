// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTree(int v, vector<vector<int>> adj[])
   {
     int result=0;
     
     vector<int> key(v,INT_MAX);
     vector<bool> mset(v,false);
     key[0]=0;
     for(int k=0;k<v;k++)
     {
         int source=-1;
         for(int i=0;i<v;i++)
         {
           if(!mset[i] && (source==-1 || key[i] < key[source]))
           source=i;
         }
         
         mset[source]=true;
         result+=key[source];
         for(int j=0;j<adj[source].size();j++)
         {
             if(adj[source][j][1]!=0 && !mset[adj[source][j][0]])
             key[adj[source][j][0]]=min(key[adj[source][j][0]],adj[source][j][1]);
         }
     }
     
     return result;
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends