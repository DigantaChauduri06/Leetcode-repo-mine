class Solution:
    def canFinish(self, n: int, pre: List[List[int]]) -> bool:
        adj = {i: [] for i in range(n+1)}
        for si, ei in pre:
            adj[si].append(ei)
        rec, vis = set(), set()
        def isCycle(node):
            vis.add(node)
            rec.add(node)
            for nd in adj[node]:
                if not nd in vis:
                    if isCycle(nd):
                        return True
                elif nd in rec:
                    return True
            rec.remove(node)
            return False
        for i in range(n):
            if isCycle(i):
                return False
        return True
        