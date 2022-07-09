// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
   void dfstopo(int source, vector<bool> &visited, vector<int> trans[])
{
    visited[source]=true;
   for(auto nebor:trans[source])
   {
       if(!visited[nebor])
       dfstopo(nebor,visited,trans);
   }
}

void dfs(int source, vector<bool> &visited, vector<int> adj[], stack<int> &s)
{
   visited[source]=true;
   for(auto nebor:adj[source])
   {
       if(!visited[nebor])
       dfs(nebor,visited,adj,s);
   }
   s.push(source);
}
   int kosaraju(int v, vector<int> adj[])
   {
     
    // step 1: tropological sort
    stack<int> s;
    vector<bool> visited(v,false);
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        dfs(i,visited,adj,s);
    }
    
    // step 2: transponse 
    vector<int> trans[v];
    for(int i=0;i<v;i++)
    {
     visited[i]=false;
     for(auto x:adj[i])
     trans[x].push_back(i);
    }
    
   //step 3: do the dfs on the topological sort stack 
   int ans=0;
   while(!s.empty())
   {
    int temp=s.top();
    s.pop();
    if(!visited[temp])
    {
       ans++;
       dfstopo(temp,visited,trans); 
    }
   }
   
   
   return ans;
   }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends