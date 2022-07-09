#include <bits/stdc++.h>
using namespace std;
int smallercount(int arr[],int n)
{
   set<int> s;
   int maxcount=0;
   for(int i=n-1;i>=0;i--)
   { 
       s.insert(arr[i]);
       int dist=distance(s.begin(),s.find(arr[i]));
       maxcount=max(maxcount,dist);
       
   }
   return maxcount;
}

int main() {
//code
int t;
cin>>t;
while(t--)
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int res=smallercount(arr,n);
    cout<<res<<endl;
}
return 0;
}