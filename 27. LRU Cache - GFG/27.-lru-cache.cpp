// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    public:
    /*creating a doubly ll that contains the key, value pair as the data*/
    class Node{
        public:
            int key;
            int val;
            Node *prev;
            Node *next;
            Node(int k, int v){
                key = k;
                val = v;
            }
    };
    
    /*Giving the, key and value to head and tail as -1,-1*/
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    int size;
    unordered_map<int, Node *> m;    /*in this map we store the key and the pointer
                                    to the node associated with it*/
                                    
    //public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
        size = cap;
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(Node *new_node){
        Node *temp = head->next;
        new_node->next = temp;
        new_node->prev = head;
        head->next = new_node;
        temp->prev = new_node;
    }
    
    void deletenode(Node * delnode){
        Node *del_node_next = delnode->next;
        Node *del_node_prev = delnode->prev;
        del_node_prev->next = del_node_next;
        del_node_next->prev = del_node_prev;
    }
    
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        // your code here
        int a;
        if(m.find(key)!=m.end()){       //key exists in map
            Node *add_of_node = m[key];     /*m[key] returns the value of its counterpair
                                        (in this case, address ofthe node associated with it)*/
            a = add_of_node->val;
            m.erase(key);
            deletenode(add_of_node);
            addnode(add_of_node);
            m[key] = head->next;
        }else{
            a = -1;
        }
        return a;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        // your code here
        if(m.find(key)!=m.end()){
            Node *add_of_node = m[key];
            add_of_node->val = value;
            deletenode(add_of_node);
            addnode(add_of_node);
            m[key] = head->next;
        }else{
            if(m.size() == size){
                m.erase((tail->prev)->key);
                deletenode(tail->prev);
            }
            Node *newnode = new Node(key, value);
            addnode(newnode);
            m.insert(pair<int, Node*>(key, newnode));
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends