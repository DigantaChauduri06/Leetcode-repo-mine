// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
   public:
   //Function to find the median of the two arrays when they get merged.
   int findMedian(int arr[], int n, int brr[], int m)
   {
       // code here
         int n1 = (n<m) ? n : m;
     int n2 = (n>m) ? n : m;
     int begin = 0, end = n1;
     
     while(begin <= end)
     {
         int i1 = (begin + end)/2;
         int i2 = (n1 + n2 + 1)/2 - i1;
         int min1 = (i1 == n1) ? INT_MAX : arr[i1];
         int min2 = (i2 == n2) ? INT_MAX : brr[i2];
         int max1 = (i1 == 0) ? INT_MIN : arr[i1- 1];
         int max2 = (i2 == 0) ? INT_MIN : brr[i2- 1];
         
         if((max1 <= min2) && (max2 <= min1))
         {
             int max = (max1 > max2) ? max1 : max2;
             int min = (min1 < min2) ? min1 : min2;
             if((n1 + n2) % 2 == 0)
                 return (double)((max + min) / 2);
             else
                 return (double)max;
         }
         else if(max1 > min2)
             end = i1 - 1;
         else
             begin = i1 + 1;
     }
   }
};

// { Driver Code Starts.

int main() {
	int t;
	cin >> t;
	
	while(t--){
	    int n, m;
	    cin >> n >> m;
	    int arr[n];
	    int brr[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> brr[i];
	    }
	    Solution obj;
	    if(n < m)
	        cout << obj.findMedian(arr, n, brr, m) << endl;
	   else
	        cout << obj.findMedian(brr, m, arr, n) << endl;
	    
	}

}  // } Driver Code Ends