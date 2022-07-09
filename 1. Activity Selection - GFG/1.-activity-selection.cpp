// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<vector<int>> v;
        for(int i=0; i<n; i++){
            v.push_back({start[i],end[i]});
        }
        
        sort(v.begin(),v.end());
        
        int count=0;
        int last=0;
        for(int i=0; i<n; i++){
            if(v[i][0]>last){
                count++;
                last=v[i][1];
            }
            else{
                last=min(last,v[i][1]);
            }
        }
        
        return count;
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends