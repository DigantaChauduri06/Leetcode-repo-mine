// { Driver Code Starts
//Initial Template for C++

/* Following program is a C implementation of 
Rabin Karp. Algorithm given in the CLRS book */
#include<bits/stdc++.h>

using namespace std;

bool search(string, string, int);


 // } Driver Code Ends
//User function Template for C++

// d is the number of characters in the input alphabet 
#define d 256 

//Function to check if the pattern is present in string or not.
bool search(string pat, string txt, int q) 
{ 
int m=txt.length();
    int n=pat.length();
    for(int i=0;i<m-n+1;i++) {
        string r = txt.substr(i,n);
        if(r == pat) {
            return true;
        }
    }
    return false;
} 

// { Driver Code Starts.

/* Driver program to test above function */
int main() 
{ 
    int t;
    cin >> t;
    
    while(t--){
	    string s, p;
	    cin >> s >> p;
	    int q = 101; // A prime number 
	    if(search(p, s, q)) cout << "Yes" << endl;
	    else cout << "No" << endl;
    }
	return 0; 
} 
  // } Driver Code Endshttps://media.geeksforgeeks.org/img-practice/check-square-1596781127.svg