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
unordered_map<Node *, Node *> oldToNew;
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        if (oldToNew.find(node) != oldToNew.end())
            return oldToNew[node];
        Node *nn = new Node(node->val);
        oldToNew[node] = nn;
        for (auto &nei : node->neighbors) {
            Node *neiNodes = cloneGraph(nei);
            nn->neighbors.push_back(neiNodes);
        }
        return nn;
    }
};