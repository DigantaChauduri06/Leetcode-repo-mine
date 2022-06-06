class Solution {
    unordered_map<int, list<int>> adj;
    vector<int> ans;
    unordered_set<int> seen, st;
public:
    vector<int> findOrder(int nc, vector<vector<int>>& preq) {
        for (auto &p : preq) {
            adj[p[0]].push_back(p[1]);
        }
        for (int i = 0;i < nc;i++) {
            if (seen.find(i) == seen.end() && !topo_sort(i)) {
                return {};
            }
        }
        return ans;
    }
private:
    bool topo_sort(int sv) {
        if (seen.find(sv) != seen.end()) return false;
        if (adj[sv].empty()) {
            if (st.find(sv) == st.end()){
                ans.push_back(sv);
                st.insert(sv);
            }
            return true;
        }
        seen.insert(sv);
        for (auto &node : adj[sv]) {
            if (!topo_sort(node)) {
                return false;
            }
        }
        seen.erase(sv);
        if (st.find(sv) == st.end()) {
            ans.push_back(sv);
            st.insert(sv);
        }
        adj[sv].clear();
        return true;
    }
};