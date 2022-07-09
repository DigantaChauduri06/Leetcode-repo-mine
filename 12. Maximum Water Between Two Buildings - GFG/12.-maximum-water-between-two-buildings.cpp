// { Driver Code Starts
//Initial Template for C++


// C++ implementation of the approach 
#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
int maxWater(int arr[], int n) 
    { 
        //Your code here
        int low=0; int high=n-1;
        int maxWater=0;
        
        while(low<=high){
            int dist = (high-low-1);
            
            maxWater= max((min(arr[low], arr[high])*dist), maxWater);
            if(arr[low]<=arr[high]){
                low++;
            }
            else{
                high--;
            }
        }
        return maxWater;
    
    }
};



// { Driver Code Starts.

// Driver code 
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int height[n];
        
        for(int i=0;i<n;i++)
        {
            cin>>height[i];
        }
        Solution ob;
        cout<<(ob.maxWater(height, n))<<endl;
    }

	 
} 

  // } Driver Code Ends