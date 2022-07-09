// { Driver Code Starts
// A Dynamic Programming based solution to compute nCr % p 
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends



class Solution
{
    public:
 int nCrModp(int n, int r) 
   { 
     
     // your code here
     vector<vector<int>>dp(n+1, vector<int>(r+1,-1));
   //   if r==0 nCr is 1 
     for(int i=0;i<=n;i++){
         dp[i][0] = 1;
     }
     //if n==r nCr is 1
     for(int i=0;i<=n;i++){
         for(int j=0;j<=r;j++){
             if(i==j)
               dp[i][j] = 1;
         }
     }
     for(int i=2;i<=n;i++){
         for(int j=1;j<=r;j++){
             if(dp[i][j] == -1 && i>j)
             dp[i][j] = fmod(dp[i-1][j-1]+dp[i-1][j],1e9+7);
         }
     }
     return dp[n][r]==-1?0:dp[n][r];
             
     
     
   } 
};

// { Driver Code Starts.
// Driver program 
int main() 
{ 
  int t, n, r;
  
  //taking count of testcases
  cin >> t;
  
  while(t--){
      
      //taking n and r
      cin >> n >> r;
      Solution ob;
      //calling method nCrModp()
      cout << ob.nCrModp(n, r) << endl;
  }
  
  return 0; 
}
  // } Driver Code Ends