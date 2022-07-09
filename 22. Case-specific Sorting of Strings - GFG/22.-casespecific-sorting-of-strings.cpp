// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        string str1="",str2="";
       for(int i=0;i<n;i++)
       {
           if(str[i]<='Z') str1+=str[i];
           else str2+=str[i];
       }
       sort(str1.begin(),str1.end());
       sort(str2.begin(),str2.end());
       int j=0,k=0;
       for(int i=0;i<n;i++)
       {
           if(str[i]<='Z')
           {
               str[i]=str1[j];
               j++;
           }
           else
           {
               str[i]=str2[k];
               k++;
           }
       }
       return str;
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
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}  // } Driver Code Ends