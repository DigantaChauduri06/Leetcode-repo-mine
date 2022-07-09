// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
   public:
   //Function to find maximum of minimums of every window size.
   vector <int> maxOfMin(int arr[], int n)
   {
       stack <int> temp;
       vector<int> ans (n,-1e9);
       temp.push(0);
       for(int i=1;i<n;i++)
       {
           while(!temp.empty() && arr[temp.top()]>arr[i])
           {
               int x=temp.top();
               temp.pop();
               int curr=temp.empty()?i-1:(i-temp.top()-2);
               if(ans[curr]<=arr[x])
                   ans[curr]=arr[x];
           }
           temp.push(i);
       }
       while(!temp.empty())
       {
               int x=temp.top();
               temp.pop();
               int curr=temp.empty()?n-1:(n-temp.top()-2);
               if(ans[curr]<arr[x])
                   ans[curr]=arr[x];            
       }
       for(int i=n-2;i>=0;i--)
       {
           if(ans[i]<ans[i+1])
               ans[i]=ans[i+1];
       }
       return ans;
   }
};



// { Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends