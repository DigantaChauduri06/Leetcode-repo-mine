//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool arraySortedOrNot(int arr[], int n) {
        // code here
        return helper(arr, 0, n);
    }
    private:
     bool helper(int *arr, int i, int n) {
         if (i == n - 1) return true;
         if (arr[i] > arr[i+1]) return false;
         if (!helper(arr, i+1, n)) return false;
         return true;
     }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        bool ans = ob.arraySortedOrNot(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends