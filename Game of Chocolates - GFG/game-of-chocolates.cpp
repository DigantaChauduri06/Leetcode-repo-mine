// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

const int Nrange = (int)(1e6+1);
class Solution{
public:
   
   
   bool game(int a, int b){
     if(a>b){
           swap(a,b);
       }
       int k=b-a;
       long double d= 1 +sqrt(5);
       d/=2;
       d*=k;
       int temp=(int)d;
       if(temp==a){
           return 0;
       }
       return 1;
   }
};


// { Driver Code Starts.


int main(){
    Solution obj;
	int tt;
	int a,b;
    cin >> tt;
	while(tt--){
        cin >> a >> b;
        bool dolly = obj.game(a,b);
        puts(dolly?"Dolly":"Bunty");
     }
 return 0;
}  // } Driver Code Ends