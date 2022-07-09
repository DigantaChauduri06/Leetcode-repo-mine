// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

 // } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
long long int floorSqrt(long long int x) 
{
   // Your code goes here
   long long root;
   for(int i=0; i*i <= x; i++)
   {
       if( i*i <= x)
       {
           root= i;
       }
   }
   return root;
}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}
  // } Driver Code Ends