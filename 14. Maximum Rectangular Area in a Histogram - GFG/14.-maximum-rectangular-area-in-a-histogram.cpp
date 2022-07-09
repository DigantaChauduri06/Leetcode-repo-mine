// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
long long getMaxArea(long long arr[], int n)
   {
       // Your code here
       vector<long long>left(n),right(n);
       stack<long long>stk;
       for(int i=0;i<n;i++)
       {
           while(!stk.empty() and arr[i]<=arr[stk.top()]){
               stk.pop();
           }
           if(stk.empty()){
               left[i]=0;
           }
           else{
               left[i]=stk.top()+1;
           }
           stk.push(i);
       }
       while(!stk.empty()){
           stk.pop();
       }
       for(int i=n-1;i>=0;i--){
           while(!stk.empty() and arr[i]<=arr[stk.top()]){
               stk.pop();
           }
           if(stk.empty()){
               right[i]=n-1;
           }
           else{
               right[i]=stk.top()-1;
           }
           stk.push(i);
       }
       long long maxi=0;
       for(int i=0;i<n;i++){
           maxi=max(maxi,(right[i]-left[i]+1)*arr[i]);
       }
       return maxi;
       
   }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends