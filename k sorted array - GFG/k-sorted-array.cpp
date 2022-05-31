// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    string isKSortedArray(int arr[], int n, int k)
    {
        //code here.
        vector<int> temp;
        for (int i = 0;i < n;i++) {
            temp.push_back(arr[i]);
        }
        sort(begin(temp), end(temp));
        for (int i = 0;i < n;i++) {
            int pos = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            if (abs(pos - i) > k) {
                return "No";
            }
        }
        return "Yes";
    }
};
/*
{3, 2, 1, 5, 6, 4}
{1, 2, 3, 4, 5, 6}

*/


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    cin>>k;
	    Solution ob;
	cout <<ob.isKSortedArray(arr, n, k)<<endl;
	}
	return 0;	 
}  // } Driver Code Ends