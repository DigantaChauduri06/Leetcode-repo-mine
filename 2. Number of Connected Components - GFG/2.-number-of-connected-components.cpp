// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>

using namespace std;

int arr[100001];
int rank1[100001];


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    int count = 0;
    public:
    //Function to merge two nodes a and b.
    int _find(int a, int par[]) {
        if (a == par[a]) return a;
        return par[a] = _find(par[a], par);
    }
    void unionNodes( int a, int b, int par[], int rank[], int n) {
        //code here
        int par_a = _find(a, par);
        int par_b = _find(b, par);
        if (par_a == par_b) return;
        count++;
        if (rank[par_a] > rank[par_b]) {
            par[par_b] = par_a;
        } else if (rank[par_a] < rank[par_b]) {
            par[par_a] = par_b;
        } else {
            par[par_a] = par_b;
            rank[par_b]++;
        }
    }
    
    //Function to determine number of connected components.
    int findNumberOfConnectedComponents( int n, int par[], int rank1[]) {
        //code here
        return n - count;
    }
};

// { Driver Code Starts.



int main() {
    int t;
    cin>>t;

    while(t--) {
        
        //taking number of nodes
        int n;
        cin>>n;

        //initializing parent array and
        //rank array
        for(int i=1; i<=n; i++) {
            arr[i] = i;
            rank1[i] = 1;
        }

        //taking number of queries
        int q;
        cin>>q;
        Solution obj;
        while(q--) {
            int a,b;
            cin>>a>>b;
            
            //calling unionNodes() function
            obj.unionNodes(a,b, arr, rank1, n);
        }

        //calling function findNumberofConnectedComponents()
        cout<<obj.findNumberOfConnectedComponents(n, arr, rank1)<<endl;
    }
    return 0;
}  // } Driver Code Ends