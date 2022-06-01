// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    typedef long long ll;
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        // sort(arr, arr+n);
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        vector<ll> vc;
        for (int i = 0;i < n;i++) {
            pq.push(arr[i]);
        }
        while (pq.size() > 1) {
            ll top1 = pq.top();
            pq.pop();
            ll top2 = pq.top();
            pq.pop();
            ll sum = top1 + top2;
            vc.push_back(sum);
            pq.push(sum);
        }
        ll sum = 0;
        for (auto &a : vc) {
            sum += a;
        }
        // cout << sum << endl;
        return sum;
    }
};


// { Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends