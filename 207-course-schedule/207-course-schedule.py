class Solution:
    def isCycleHelper(self,sv, adj, vis, recVis):
        vis[sv] = True
        recVis[sv] = True
        for node in adj[sv]:
            if vis[node]:
                if recVis[node]:
                    return True
            else:
                if self.isCycleHelper(node, adj, vis, recVis):
                    return True
        recVis[sv] = False
        return False
    def isCyclic(self, V, adj):
        # code here
        vis = [False for _ in range(V+1)]
        recVis = [False for _ in range(V+1)]
        for i in range(V):
            if not vis[i]:
                if self.isCycleHelper(i, adj, vis, recVis):
                    return True
        return False
    def canFinish(self, n: int, pre: List[List[int]]) -> bool:
        adj = {i: [] for i in range(n+1)}
        for si, ei in pre:
            adj[si].append(ei)
        rec, vis = set(), set()
        return not self.isCyclic(n,adj)
        # def isCycle(node):
        #     vis.add(node)
        #     rec.add(node)
        #     for nd in adj[node]:
        #         if not nd in vis:
        #             if isCycle(nd):
        #                 return True
        #         elif nd in rec:
        #             return True
        #     rec.remove(node)
        #     return False
        # return not isCycle(0)