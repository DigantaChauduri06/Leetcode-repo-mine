// { Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
Node* traverse(int post[],unordered_map<int,int> &m,int instart,int inend,int poststart,int postend)
{
   if(instart>inend||poststart>postend)
   {
       return NULL;
   }
   Node* node=new Node(post[postend]);
   int t=m[post[postend]];
   int no=t-instart;
   node->left=traverse(post,m,instart,t-1,poststart,poststart+no-1);
   node->right=traverse(post,m,t+1,inend,poststart+no,postend-1);
   return node;
}
//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n) {
   // Your code here
   unordered_map<int,int> m;
   for(int i=0;i<n;i++)
   {
       m[in[i]]=i;
   }
   return traverse(post,m,0,n-1,0,n-1);
}

