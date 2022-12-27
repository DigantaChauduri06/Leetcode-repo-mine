//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n) {
    	// Your code here
    	vector<vector<int>> T;
        priority_queue <int, vector<int>, greater<int>> pq;
    	for (int i = 0;i < n;i++) {
    	    T.push_back({arr[i], dep[i]});
    	}
    	sort(begin(T),end(T), comp);
    	int pl = 1;
    	pq.push(T[0][1]);
    	for (int i = 1;i < n;i++) {
    	    if (T[i][0] > pq.top()) {
    	        pq.pop();
    	        pq.push(T[i][1]);
    	    } else {
    	        pl+=1;
    	        pq.push(T[i][1]);
    	    }
    	}
    	return pl;
    	
    	
    }
    private:
    static bool comp(vector<int> &a, vector<int> &b) {return a[0] < b[0];}
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends