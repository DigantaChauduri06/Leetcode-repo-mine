// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    
     long long trappingWater(int a[], int n){
        //3 Pass Solution
        
        vector<long long int>left(n),right(n);
        int val=a[0],j=0;
        for(long long int i=0;i<n;i++){
            if(val<a[i]){
                val=a[i];
            }
            left[i]=val;
        }
        val=a[n-1];
        for(long long int i=n-1;i>=0;i--){
            if(val<a[i]){
                val=a[i];
            }
            right[i]=val;
        }
        
      
        long long int ans=0;
        for(long long int i=0;i<n;i++){
            long long int mn=min(left[i],right[i])-a[i];
            ans+= mn>=0?mn :0;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends