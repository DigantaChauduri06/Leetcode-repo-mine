// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find lexicographic rank of a string.
long long d=1000000007;
       long long fact(long long n){
       long long ans=1;
       for(int i=n;i>1;i--)
       ans=(ans*i)%d;
       return ans;
   }
   int findRank(string S) 
   {   int a[26]={0};
       string temp=S;
       long long ans=1;
       sort(temp.begin(),temp.end());
       for(int i=0;i<S.length();i++){
         int x = temp.find(S[i]);
         if(a[(int)S[i]-97] == 1)
         return 0;
         a[(int)S[i]-97]++;
         int count=0;
         for(int j=0;j<((int)S[i]-97);j++) {
             if(a[j] == 1)
             count++; }
         ans=(ans+(x-count)*fact(S.length()-i-1))%d; }
       return ans; } 
};

// { Driver Code Starts.


int main()
{
    string S;
    int t;
    cin>>t;
    while(t--)
    {
     
        cin>>S;
        Solution obj;
        cout<<obj.findRank(S)<<endl;
    }
}
  // } Driver Code Ends