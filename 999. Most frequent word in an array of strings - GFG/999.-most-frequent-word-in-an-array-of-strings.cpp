// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution
{
    public:
    //Function to find most frequent word in an array of strings.
string mostFrequentWord(string arr[], int n) 
    {
        unordered_map<string,int> m;
        unordered_map<string,bool> mc;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
            mc[arr[i]]=false;
        }
        int maxi=0;
        string ans="";
        for(int i=0;i<n;i++){
            if(mc[arr[i]]==false){
              if(m[arr[i]]>=maxi) 
              {
                  maxi=m[arr[i]];
                  ans=arr[i];
              }
              mc[arr[i]]=true;
            }
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

        string arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.mostFrequentWord(arr, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends