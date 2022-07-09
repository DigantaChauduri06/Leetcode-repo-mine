// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
   public:
   long long maximumAmount(int arr[], int n){
       // Your code here
       int F[n][n];
   for (int i = 1; i < n; i++)
       F[i-1][i] = max(arr[i-1], arr[i]);
   for (int k = 2; k < n; k++) {
       for (int j = k; j < n; j++) {
           int i = j-k, f1 = F[i+1][j], f2 = F[i][j-1];
           if (k % 2) F[i][j]=max(arr[i]+f1,arr[j]+f2);
           else F[i][j]=min(f1,f2);
       }
   }
   return F[0][n-1];
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
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends