// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to rearrange the characters in a string such that 
    //no two adjacent characters are same.
const int MAX_CHAR=26;
   typedef pair<int,char> pi;
   string rearrangeString(string str)
   {
    // Your code here
    int n=str.length();
    int count[MAX_CHAR]={0};
    
    for(int i=0;i<n;i++){
        count[str[i]-'a']++;
    }
    priority_queue<pi> maxHeap;
    for(char c='a';c<='z';c++){
        int val=c-'a';
        if(count[val]) maxHeap.push({count[val],c});
    }
    
    str="";
    pi prev={-1,'#'};
    
    while(!maxHeap.empty()){
        pi curr = maxHeap.top();
        maxHeap.pop();
        str=str+curr.second;
        curr.first--;
        
        if(prev.first>0) maxHeap.push(prev);
        
        prev=curr;
        
    }
    
    if(n==str.length()) return str;
    else return "";
   }
};

// { Driver Code Starts.

int checker(string str, string pat)
{
    int freq[26];
    for(int i=0;i<26;i++)
        freq[i]=0;
    if(str.length()!=pat.length())
        return 0;
    for(int i=0;i<str.length();i++)
    {
        freq[str[i]-97]--;
        if(pat[i]<97 || pat[i]>122)
            return 0;
        freq[pat[i]-97]++;
    }
    for(int i=0;i<26;i++)
        if(freq[i]!=0)
            return 0;
    for(int i=0;i<pat.length()-1;i++)
        if(pat[i]==pat[i+1])
            return 0;
    return 1;
}

int main()
{
	int t;
	cin>>t;
	cin.ignore(INT_MAX, '\n');
	while(t--)
	{
	    string str,ret;
	    cin>>str;
	    Solution ob;
	    ret = ob.rearrangeString(str);
	    cout << checker(str, ret) << endl;
	}
    return 0;
}  // } Driver Code Ends