// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *createNewNode(int value) {
    Node *temp = new Node;
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

Node *newNode(Node *root, int data) {
    if (root == NULL)
        root = createNewNode(data);
    else if (data < root->data)
        root->left = newNode(root->left, data);
    else
        root->right = newNode(root->right, data);

    return root;
}


 // } Driver Code Ends
// User function Template for C++

// Function to return a list containing the inorder traversal of the BST.
vector<int> inOrder(Node *root) {
    // code here
    if(!root)
    return {};
    
    vector<int> ans;
    vector<int> l = inOrder(root->left);
    if(l.size())
    {
        for(auto i : l)
        ans.push_back(i);
    }
    ans.push_back(root->data);
    vector<int> r = inOrder(root->right);
    if(r.size())
    {
        for(auto i : r)
        ans.push_back(i);
    }
    return ans;
}

// { Driver Code Starts.

int main() {

    int testcases;
    cin >> testcases;
    while (testcases--) {
        Node *root = NULL;
        int sizeOfArray;
        cin >> sizeOfArray;
        int arr[sizeOfArray];

        for (int i = 0; i < sizeOfArray; i++) cin >> arr[i];

        for (int i = 0; i < sizeOfArray; i++) {
            root = newNode(root, arr[i]);
        }

        vector<int> res = inOrder(root);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends