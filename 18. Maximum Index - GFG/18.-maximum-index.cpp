// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
  int maxIndexDiff(int A[], int n) 
   { 
      
       int p=INT_MIN;
       int diff=0;
       for(int i=0;i<n-1;i++)
       {
           for(int j=n-1;j>i;j--)
           {
               if(A[i] <= A[j])
               {
               diff=j-i;
               break;
               }
           }
            p=max(diff,p);
       }
       return p;
   }
};

// { Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
}   // } Driver Code Ends