/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        unordered_map<Node *,Node *> mpp;
        auto res = dfs(node, mpp);
        return res;
    }
private:
    Node* dfs(Node *node, unordered_map<Node *, Node *> &oldToNew) {
        if (oldToNew.find(node) != oldToNew.end()) 
            return oldToNew[node];
        Node *nn = new Node(node->val);
        oldToNew[node] = nn;
        // Trivarse The neighbors
        for (auto &nei : node->neighbors) {
            nn->neighbors.push_back(dfs(nei, oldToNew));
        }
        return nn;
    }
};