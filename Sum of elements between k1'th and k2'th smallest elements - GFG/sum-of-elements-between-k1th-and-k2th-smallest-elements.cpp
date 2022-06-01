// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
typedef long long ll;
    public:
    long long sumBetweenTwoKth(ll A[],ll N,ll k1,ll k2)
    {
        // Your code goes here
        if (k1  == k2) return 0;
        if (k1+1 == k2) return 0;
        auto first = kthSmallest(A, N, k1);
        auto second = kthSmallest(A, N, k2);
        ll f = first.second; 
        ll s = second.second; 
        ll diff = (s - f); 
        return diff - second.first;
    }
private:
    pair<ll,ll> kthSmallest(ll *A, ll N, ll k) {
        priority_queue<ll> pq;
        for(ll i = 0;i < N;i++) {
            pq.push(A[i]);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        ll sum = 0;
        ll top = pq.top();
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
        return {top, sum};
    } 
};

// { Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}
  // } Driver Code Ends