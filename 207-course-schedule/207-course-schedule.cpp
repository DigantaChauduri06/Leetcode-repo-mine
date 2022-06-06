class Solution {
    unordered_map<int, list<int>> adj;
    set<int> st;
public:
    bool canFinish(int numCourses, vector<vector<int>>& P) {
        for (auto &p : P) {
            adj[p[0]].push_back(p[1]);
        }
        for (int i = 0;i < numCourses;i++) {
            if (st.find(i) == st.end() && !dfs(i)) return false;
        }
        return true;
    }
private:
    bool dfs(int sv) {
        if (st.find(sv) != st.end()) return false;
        if (adj[sv].empty()) return true;
        
        st.insert(sv);
        for (auto &node : adj[sv]) {
            if (!dfs(node)) return false;
        }
        adj[sv].clear();
        st.erase(sv);
        return true;
    }
};