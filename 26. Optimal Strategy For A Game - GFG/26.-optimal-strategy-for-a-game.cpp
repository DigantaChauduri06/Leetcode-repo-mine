// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
long long solve(int nums[], int i, int j, long long sum, vector<vector<long long>> &dp){
        if(dp[i][j] != -1)
            return dp[i][j];            
        if(j == i)  return nums[i];         
        return dp[i][j] = max(sum - solve(nums, i + 1, j, sum - nums[i], dp), sum - solve(nums, i, j - 1, sum - nums[j], dp));
    }
    
    long long maximumAmount(int arr[], int n){        
        long long totSum = 0;
        vector<vector<long long>> dp(n, vector<long long>(n , -1));
        for(int i = 0; i < n; i++){
            totSum += arr[i];
        }
        return solve(arr, 0 , n - 1, totSum,dp);
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