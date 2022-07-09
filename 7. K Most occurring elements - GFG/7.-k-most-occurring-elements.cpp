// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
// Function to print the k numbers with most occurrences 

class Solution
{
    public:
    //Function to return the sum of frequencies of k numbers
    //with most occurrences in an array.
int kMostFrequent(int arr[], int n, int k) 
    { 
    	// Your code here
    	unordered_map<int,int> mp;
    	priority_queue<int> pq;
    	
    	for(int i=0;i<n;i++){
    	    mp[arr[i]]++;
    	}
    	
    	int sum=0;
    	for(auto itr:mp){
    	   pq.push(itr.second);
    	}
    	
    	while(k--){
    	    sum+=pq.top();
    	    pq.pop();
    	}
    	
    	return sum;
    } 
};

// { Driver Code Starts.
// Driver program to test above 
int main() 
{
	int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.kMostFrequent(arr, n, k) << endl; 
    }

	return 0; 
} 
  // } Driver Code Ends