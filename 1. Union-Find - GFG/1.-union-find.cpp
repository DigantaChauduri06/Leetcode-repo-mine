// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to merge two nodes a and b.
    int find_parent(int a, int par[]) {
        if (par[a] == a) return a;
        return par[a] = find_parent(par[a], par);
    }
    void union_(int a, int b, int par[], int rank[]) {
        //code here
        int par_a = find_parent(a, par);
        int par_b = find_parent(b, par);
        
        if (par_a == par_b) return;
        
        if (rank[par_a] > rank[par_b]) {
            par[par_a] = par_b;
        } else if (rank[par_a] < rank[par_b]) {
            par[par_b] = par_a;
        } else {
            par[par_a] = par_b;
            rank[par_b]++;
        }
        
    }
    
    //Function to check whether 2 nodes are connected or not.
    bool isConnected(int a,int b, int par[], int rank[])
    {
        //code here
        int par_a = find_parent(a, par);
        int par_b = find_parent(b, par);
        return par_a == par_b;
    }
};

// { Driver Code Starts.

int main() {
    //taking number of testcases
    int t;
    cin>>t;
    while(t--) {
        
        //taking number of elements
        int n;
        cin>>n;
        
        
        int par[n+1];
        int rank1[n+1];

        //initializing the parent and
        //the rank array
        for(int i=1; i<=n; i++) {
            par[i] = i;
            rank1[i] = 1;
    }
    
    //taking number of queries
    Solution obj;
    int q;
    cin>>q;
    while(q--) {    
        int a,b;
        char c;
        cin>>c>>a>>b;
        
        //if query type is 'U'
        //then calling union_ method
        if(c=='U')
        {
            obj.union_(a,b, par, rank1);
        }
        else//else calling isConnected() method
        cout<<obj.isConnected(a,b, par, rank1)<<endl;
    }
    }
    return 0;
}
  // } Driver Code Ends