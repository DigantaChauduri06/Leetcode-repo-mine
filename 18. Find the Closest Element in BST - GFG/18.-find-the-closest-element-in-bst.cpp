// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



 // } Driver Code Ends




class Solution
{
   public:
   //Function to find the least absolute difference between any node
//value of the BST and the given integer.
int floor(Node *root, int x) {
int res = -1;
while(root){
if(root->data==x) { return root->data; }
else if(root->data>x)  { root = root->left; }
else { res = root->data; root = root->right; }
}
return res;
}

int findCeil(Node* root, int x) {
   if (root == NULL) return -1;

   // Your code here
   int res;
   
while(root){
if(root->data==x) { return root->data; }
else if(root->data>x)  { res = root->data; root = root->left; }
else {  root = root->right; }
}
return res;
}

   int minDiff(Node *root, int K)
   {
       //Your code here
       int x = floor(root,K);
       int y = findCeil(root,K);
       
       if(x!=-1 && y!=-1) { return min(abs(x-K),abs(y-K)); }
       else if(x==-1) { return abs(y-K); }
       else { return abs(x-K); }
   }
};


// { Driver Code Starts.

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



int main() {
   
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       int k = stoi(s);
       // getline(cin, s);

        Solution ob;
       cout << ob.minDiff(root1, k);
        cout << endl;
       //cout<<"~"<<endl;
   }
   return 0;
}
  // } Driver Code Ends