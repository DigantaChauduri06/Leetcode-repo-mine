// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
bool check(int A[], int N, int M, int max_sum){
    int cnt = 1, s = 0;
    for(int i=0; i<N; i++){
        if(A[i] > max_sum)
            return false;
        if(s+A[i] > max_sum){
            s = 0;
            cnt += 1;
        }
        s += A[i];
    }
    return cnt <= M;
}
int findPages(int A[], int N, int M) 
{
    if(M > N)
        return -1;
    long l = 1, r = accumulate(A, A+N, 0);
    while(l < r){
        int m = (l+r)/2;
        if(check(A, N, M, m))
            r = m;
        else
            l = m+1;
    }
    return l;
}
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends