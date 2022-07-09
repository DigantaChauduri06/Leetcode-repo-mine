// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution{
    public:
    //Complete this function
struct compare {
        bool operator()(pair<int, int> p1, pair<int, int> p2) {
            if (p1.first == p2.first) return p1.second > p2.second; 
            return p1.first < p2.first;
      }
    };
    
    vector<int> sortByFreq(int arr[],int n)
    {
        //Your code here
        vector<int> ans;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) m[arr[i]]++;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        for (auto x: m) pq.push(make_pair(x.second, x.first));
        
        while (!pq.empty()) {
            pair<int, int> t = pq.top();
            int count = t.first;
            while (count--) ans.push_back(t.second);
            pq.pop();
        }
        
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution obj;
	    vector<int> v;
	    v = obj.sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}

  // } Driver Code Ends