// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
int celebrity(vector<vector<int> >& M, int n) 
    {
        // Method 1
        vector<int> row(n);
        vector<int> col(n);
        
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                if(M[i][j]==1)sum++;
            }
            row[i]=sum;
        }
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                if(M[j][i]==1)sum++;
            }
            col[i]=sum;
        }
        
        for(int i=0;i<n;i++){
            if(col[i]==n-1 and row[i]==0)return i;
        }
        return -1;
        
        // Method 2
        stack<int> s;
        for(int i=0;i<n;i++){
            s.push(i);
        }
        
        while(s.size()>1){
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            if(M[a][b]==1){
                s.push(b);
            }else{
                s.push(a);
            }
        }
        
        int ans=s.top();
        int sumOne=0,sumZero=0;
        for(int i=0;i<n;i++){
            if(M[i][ans]==1)sumOne++;
        }
        for(int i=0;i<n;i++){
            if(M[ans][i]==0)sumZero++;
        }
        if(sumOne==n-1 and sumZero==n)return ans;
        else return -1;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends