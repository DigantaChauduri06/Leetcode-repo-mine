// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to check if a string is subsequence of other string.
bool isSubSequence(string A, string B)
   {
       //code here
       stack<char> s;
       
       for(int i=0;i<A.length();i++)
           s.push(A[i]);
           
       for(int i=(B.length()-1);i>=0;i--)
       {
           if(!s.empty() && i>=0)
           {
               if(s.top() == B[i])
                   s.pop();
           }
           if(s.empty())
               return true;
       }
       return false;
   }
};

// { Driver Code Starts.
    
int main() {
	
	int t;
	cin>>t;
	while(t--){
	    string A, B; cin>>A>>B;
	    Solution ob;
	    bool ans = ob.isSubSequence(A, B);
	    if(ans == true)
	        cout<<"True"<<endl;
	    else
	        cout<<"False"<<endl;
	}
	return 0;
}  // } Driver Code Ends