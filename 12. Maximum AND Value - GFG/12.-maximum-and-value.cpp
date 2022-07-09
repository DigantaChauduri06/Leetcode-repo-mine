// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
 
class Solution
{
   public:
  
    int checkBit(int pattern , int arr[], int n){
      int cnt = 0;
      for(int i=0; i<n; i++){
          if((pattern&arr[i]) == pattern) cnt++;
      }
      return cnt;
  }
  
   // Function for finding maximum AND value.
   int maxAND (int arr[], int N)
   {
       // Your code here
       
        int res = 0;
      int  cnt;
      for(int bit = 31; bit >= 0; bit--){
          cnt = checkBit((res|(1<<bit)),arr,N);
          if(cnt>=2){
              res |= (1<<bit);
          }
      }
      return res;
      
   }
};

// { Driver Code Starts.
 
// Driver function
int main()
{
    int t;
    cin>>t;//testcases
    while(t--)
    {
        int n;
        cin>>n;//input n
        int arr[n+5],i;
        
        //inserting elements
        for(i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        //calling maxAND() function
        cout <<  obj.maxAND(arr,n)<<endl;
    }
    return 0;
}  // } Driver Code Ends