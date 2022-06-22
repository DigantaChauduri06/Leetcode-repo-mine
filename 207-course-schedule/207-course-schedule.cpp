class Solution {
    map<int, list<int>> adj;
    unordered_set<int> visited;
public:
    bool canFinish(int nc, vector<vector<int>>& prereq) {
        // creating adj list
        for (auto &lists : prereq) {
            adj[lists[0]].push_back(lists[1]);
        }
        // CHECK for dis-connected component
        for (int i = 0;i < nc;i++) {
            if (visited.find(i) == visited.end()) {
                if (!dfs(i)) 
                    return false;
            }
        }
        return true;
    }
private:
    bool dfs(int sv) {
        // check for cycles
        if (visited.find(sv) != visited.end()) 
            return false;
        if (adj[sv].empty()) 
            return true;
        visited.insert(sv);
        for (auto &node : adj[sv]) {
            if (!dfs(node)) 
                return false;
        }
        // here in this point we if we don't find any loop then we reached a position where that course could be complete so we can remove that dependency
        adj[sv].clear();
        visited.erase(sv);
        return true;
    }
};