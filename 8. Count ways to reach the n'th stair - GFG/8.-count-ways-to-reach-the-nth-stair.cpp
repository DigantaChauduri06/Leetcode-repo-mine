// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
int countWays(int n)
    {
        //uses fibonacci sequence to solve 
        
        
        //no of ways when person is on nth step
        long long int n1 = 0;
        //no of ways when person is on (n-1)th step
        long long int n2 = 1;
        //ans no of ways
        long long int ans;
        
        for(int i=0;i<n;i++){
            ans = (n1 + n2) % 1000000007;
            n1 = n2 % 1000000007;
            n2 = ans;
        }
        return ans ;
    }
    
};



// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}
  // } Driver Code Ends