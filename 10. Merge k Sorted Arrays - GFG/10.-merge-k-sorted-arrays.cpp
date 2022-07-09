// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++


# define pi pair<int,vector<int>>

class Solution
{
   public:
   //Function to merge k sorted arrays.
   vector<int> mergeKArrays(vector<vector<int>> arr, int K)
   {
       priority_queue<pi,vector<pi>, greater<pi>> q;
       for(int i =0 ; i<arr.size() ;i++)
       {
           q.push({arr[i].size(),arr[i]});
       }
       
       while(q.size()!=1)
       {
           auto i = q.top();
           q.pop();
           auto j = q.top();
           q.pop();
           vector<int> res;
           merge(i.second,j.second,res);
           q.push({res.size(),res});
       }
       
       return q.top().second;
   }
   
   void merge(vector<int> a,vector<int> b,vector<int> &c)
   {
       int i = 0 , j = 0;
       while(i<a.size() &&j <b.size())
       {
           if(a[i] > b[j])
           {
               c.push_back(b[j]);
               j++;
           }
           else
           {
               c.push_back(a[i]);
               i++;
           }
       }
       
       while(i<a.size())
       {
           c.push_back(a[i]);
           i++;
       }
       
       while(j<b.size())
       {
           c.push_back(b[j]);
           j++;
       }
   }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends