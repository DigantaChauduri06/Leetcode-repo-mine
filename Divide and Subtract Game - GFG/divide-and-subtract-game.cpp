// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
 public:
   string divAndSub(int N) {
       // code here
       if(N == 1)
           return "Arya";
       
       int a[N+1] = {0};
       
       for(int i=1; i<=5; i++)
           a[i] = 1;
           
       for(int i=6; i<=N; i++)
       {
           if (a[i/2] == 0)
               a[i] = 1;
           else if (a[i-2] == 0)
               a[i] = 1;
               
           if (a[i/3] == 0)
               a[i] = 1;
           else if (a[i-3] == 0)
               a[i] = 1;
           
           if (a[i/4] == 0)
               a[i] = 1;
           else if (a[i-4] == 0)
               a[i] = 1;
               
           if (a[i/5] == 0)
               a[i] = 1;
           else if (a[i-5] == 0)
               a[i] = 1;
       }
       
       if (a[N] == 1)
           return "Jon";
       else
           return "Arya";
   }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.divAndSub(N) << endl;
    }
    return 0;
}  // } Driver Code Ends