// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
ll findSubarray(vector<ll> arr, int n ) 
   {
       unordered_map<int,int> umap;
       umap[0]=1;
       int presum=0;
       int count=0;
       for(int i=0;i<n;i++)
       {
           presum+=arr[i];
           if(umap.count(presum)==0)
           umap[presum]=1;
           else
           {
               
               count+=umap[presum];
               umap[presum]++;
           }
       }
       return count;
   }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}  // } Driver Code Ends