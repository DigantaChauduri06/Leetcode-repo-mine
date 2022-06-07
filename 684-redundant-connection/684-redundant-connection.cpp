class disjointSet {
    vector<int> parent;
    vector<int> *rank;
public:
    disjointSet(vector<int> &parent, int V) {
        this->parent = parent;
        rank = new vector<int>(V, 0);
    }
    int findParent(int v) {
        if (v == parent[v]) return v;
        return parent[v] = findParent(parent[v]);
    }
    bool isCycle_union(int u, int v) {
        // find parent
        u = findParent(u);
        v = findParent(v);
        // If both sets have same parent then they create a cycle 
        if (u == v) return true;
        // if we join with larger (rank / size) tree with smaller rank / size tree then we find op will be optimized 
        if (rank->at(u) > rank->at(v)) {
            parent[u] = v;
        } else if (rank->at(v) > rank->at(u)) {
            parent[v] = u;
        } else {
            // we can attached the node to anywhere and where we attached we just adjust the rank
            parent[v] = u;
            rank->at(u)++;
        }
        // no cycle
        return false;
    }
    // ~disjointSet() {
    //     delete[] rank;
    //     delete rank;
    // }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent;
        int sz = size(edges);
        for (int i = 0;i <= sz;i++) {
            parent.push_back(i);
        }
        disjointSet *d1 = new disjointSet(parent, sz+1);
        for (auto &ed : edges) {
            if (d1->isCycle_union(ed[0], ed[1])) {
                return {ed[0], ed[1]};
            }
        }
        return {};
    }
};