// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of jumps to reach the end of the array.
int minimumJumps(int arr[], int n){
       
       if(n<=1){
           return 0;
       }
       if(arr[0]==0){
           return -1;
       }
       int maxrange=arr[0];
       int jumps=1;
       int step=arr[0];
       for(int i=1;i<n;i++){
           if(i==n-1){
               return jumps;
           }
           maxrange=max(maxrange,i+arr[i]);
           step--;
           if(step==0){
               jumps++;
           
           if(i>=maxrange)
               return -1;
           
           step=maxrange-i;
           }
       }
       
   }
};

// { Driver Code Starts.
int main()
{
    //taking count of testcases
    int t;
    cin>>t;
    while(t--)
    {
        
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minimumJumps(arr, n)<<endl;    // Function to calculate minimum number of jumps
    }
    return 0;
}  // } Driver Code Ends