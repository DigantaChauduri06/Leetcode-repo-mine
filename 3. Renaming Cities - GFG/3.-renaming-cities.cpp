// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node{
    bool isEndOfWord;
    int count1;
    map<char, Node *> mp;
};

Node *newNode(){
    Node *temp = new Node();
    temp->isEndOfWord = false;
    // int count1 = 0;
    return temp;
}


 // } Driver Code Ends
//User function template for C++

// arr : array of strings
// n : count of the number of strings in the array
class Solution
{
    public:
void helper(string s, Node *root){
       string ans ="";
       bool flag = false;
       Node *curr = root;
       for(int i =0; i<s.length(); ++i){
           if(!flag) ans+=s[i];
           if(curr->mp.find(s[i])==curr->mp.end()){
               flag = true;
               curr->mp[s[i]] = newNode();
           }   
           curr = curr->mp[s[i]];
       }
       if(curr->isEndOfWord)cout << ans << " " << curr->count1+1 << endl;
       else cout << ans << endl;
       curr->isEndOfWord = true;
       curr->count1++;
   }
   void check(string *arr, int n){
       //code here
       Node * root = newNode();
       for(int i =0; i<n; ++i){
           helper(arr[i], root);
       }
   }

};




// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string arr[n];
        for(int i = 0;i<n;i++){
            string s;
            cin >> s;
            arr[i] = s;
        }
        Solution obj;
        obj.check(arr,n);
    }
    return 0;
}
  // } Driver Code Ends