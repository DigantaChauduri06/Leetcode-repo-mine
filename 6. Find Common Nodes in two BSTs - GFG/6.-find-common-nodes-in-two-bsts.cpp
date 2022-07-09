// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the nodes that are common in both BST. 
vector <int> findCommon(Node *root1, Node *root2)
    {
        stack<Node *> s1,s2;
        Node *curr1 = root1 , *curr2 = root2;
        vector<int> v;
        while((curr1 != NULL || !s1.empty() ) && (curr2 != NULL || !s2.empty() ))
        {
            while(curr1!=NULL)
            {
                s1.push(curr1);
                curr1 = curr1 -> left; 
            }
               
                
            while(curr2!=NULL)
            {
                s2.push(curr2);
                curr2 = curr2 -> left;     
            }
        
                
            Node *top1 = s1.top() , *top2 = s2.top();
            
            if(top1->data == top2 -> data)
            {
                v.push_back(top1->data);
                
                s1.pop();
                s2.pop();
                curr1 = top1->right;
                curr2 = top2->right;
            }
            else if(top1->data < top2 -> data)
            {
                s1.pop();
                curr1 = top1 -> right;
            }
            else if(top1->data > top2 -> data)
            {
                s2.pop();
                curr2 = top2 -> right;
            }
            
            //cout<<"TOP1 : " << top1-> data <<endl;
            //cout<<"TOP2 : " << top2-> data <<endl;
                
        }
        
        return v;
    }
};




// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root1 = buildTree(s);

        getline(cin,s);
        Node* root2 = buildTree(s);
        Solution ob;
        vector <int> res = ob.findCommon(root1, root2);
        for (int i : res)
            cout << i << " ";
        cout<< endl;
    }

	return 1;
}  // } Driver Code Ends