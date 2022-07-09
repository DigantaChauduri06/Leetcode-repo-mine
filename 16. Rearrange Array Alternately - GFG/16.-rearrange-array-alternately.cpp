// { Driver Code Starts
// C++ program to rearrange an array in minimum 
// maximum form 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Functisdfon to rearrange  the array elements alternately.
void rearrange(long long *arr, int n) 
   { 
    
    // Your code here
    vector<int> max;
    vector<int> min;
    vector<int> ans;
    if(n%2==0){
        for(int i=n-1;i>n/2-1;i--){
        max.push_back(arr[i]);
        }
        for(int i=0;i<n/2;i++){
            min.push_back(arr[i]);
        }
    }
    else{
        for(int i=n-1;i>=n/2;i--){
            max.push_back(arr[i]);
        }
        for(int i=0;i<=n/2;i++){
            min.push_back(arr[i]);
        }
        
    }
    
    int i=0,j=0;
    int l1=max.size();
    int l2=min.size();
    
    while(i<l1 && j<l2){
        ans.push_back(max[i]);
        ans.push_back(min[i]);
        i++;
        j++;
    }
    while(i<l1){
        ans.push_back(max[i]);
    }
    while(j<l2){
        ans.push_back(min[i]);
    }
    
    for(int i=0;i<n;i++){
        arr[i]=ans[i];
    }
     
   }
};

// { Driver Code Starts.

// Driver program to test above function 
int main() 
{
    int t;
    
    //testcases
    cin >> t;
    
    while(t--){
        
        //size of array
        int n;
        cin >> n;
        
        long long arr[n];
        
        //adding elements to the array
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        
        //calling rearrange() function
        ob.rearrange(arr, n);
        
        //printing the elements
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 
  // } Driver Code Ends